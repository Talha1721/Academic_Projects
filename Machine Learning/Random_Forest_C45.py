import pandas as pd
import operator
import numpy as np
from collections import Counter
import math

# Node is used to create a decision tree
# Nodes are connected sequentially with each other upto the final decision nodes
# Node.children helps to create sub brunches of the decision tree
# Node works as linked list

class Node:

    def __init__(self, feature:str , previous_feature_value:str , decision:str , children:list):
        self.feature = feature
        self.previous_feature_value = previous_feature_value
        self.decision = decision
        self.children = []


# This is for calculating entropy of a feature(target or others) from a data table
def entropy_of_a_feature(feature_values):
    cnt = Counter(feature_values)  # Counter calculates the propotion of class
    probs = []
    for i,j in cnt.items():
        probs.append( j / len(feature_values))

    entropy=0
    for prob in probs:
        entropy=entropy+(-prob * math.log(prob,2))

    return entropy


# This is for calculating information gain of a feature from a data table
def information_gain(df, split_feature_name, target_feature_name):
    total_entropy = entropy_of_a_feature(df[target_feature_name])
    df_split = df.groupby(split_feature_name)

    entropy_d = {}
    for i,j in df_split:
        entropy_d[i] = entropy_of_a_feature(j[target_feature_name])

    remaining_entropy = 0
    for i,j in df_split:
        remaining_entropy = remaining_entropy + len(j)/ len(df) * entropy_d[i]

    info_gain = total_entropy - remaining_entropy
    return info_gain



def c4_5 (node_no, data,  features, target_feature, present_node):

    global root  # this veriable is used after train one tree for prediction by traversing that tree (see prediction function)
    if node_no != 0:
        feature_value = data[present_node.feature]
        feature_value = list(feature_value)
        feature_value = feature_value[0]
        data.drop(present_node.feature, inplace=True, axis=1)
        features.remove(present_node.feature)

    GainRatio = {}
    for i in range(0, len(features)): # iterate for each features
        feature_val_count = data[features[i]]
        feature_val_count = np.array(feature_val_count)
        feature_val_count = np.unique(feature_val_count) # contains each feature's unique values
        if len(feature_val_count) == 1:  # if this feature has only one value
            unique = 1
            continue
        else:
            unique = 0
        info_gain = information_gain(data,features[i], target_feature)
        split_info = entropy_of_a_feature( data[features[i]])
        GainRatio[features[i] ] = info_gain / split_info

    GR = sorted(GainRatio.items(), key=operator.itemgetter(1), reverse=True)
    #print Gain Ratio
    print("Gain Ratio : ",GR)  #last GR is null and extra for reccursion

    if node_no == 0:

        root = Node(GR[0][0], None, None, None )
        node_no = node_no + 1
        present_node = root

        df_split = data.groupby(present_node.feature)
        for i,j in df_split:
            feature_value = i
            features = j.columns
            features = list(features)
            features.remove(target_feature)
            decision = j[target_feature]
            decision = np.array(decision)
            if len(np.unique(decision)) == 1:
                n=Node(None, feature_value, decision[0] , None)
                present_node.children.append(n)
                continue
            c4_5(node_no, j, features, target_feature, present_node)

    else:

        if unique == 1:  # this means present feature has only one values
            cnt = Counter(data[target_feature])
            cnt = sorted(cnt.items(), key=operator.itemgetter(1), reverse=True) #
            n=Node(None, feature_value, cnt[0][0], None)
            present_node.children.append(n)

        else: # this means present feature has multiple values
           n = Node(GR[0][0], feature_value, None, None)
           present_node.children.append(n)
           present_node = n
           df_split = data.groupby(present_node.feature)

           for i,j in df_split:
               features = j.columns
               features = list(features)
               features.remove(target_feature)
               decision = j[target_feature]
               decision = np.array(decision)
               if len(np.unique(decision)) == 1:
                  present_node.children.append(Node(None, i , decision[0], None))
                  continue
               c4_5(node_no, j, features, target_feature, present_node)


# This is for prediction by trained tree with query(testing) instance
def prediction(query, root):  # root : trained tree  ;  query : testing instance
    current = root
    while(True):
        value = query[current.feature][0]

        for i in range(0, len(current.children)):
            if value == str(current.children[i].previous_feature_value) :
                current= current.children[i]  # updating current
                break
        if current.decision != None:
            return current.decision
            break


# This is for calcuating majority vote of results, produced by three decision trees
def majority_voting(predition):
    predition = np.array(predition)
    p = np.unique(predition)

    prediction_count = {}
    for i in range(0, len(p)):
        prediction_count[p[i]] = 0

    for i in range(0, len(predition)):
        prediction_count[predition[i]] = prediction_count[predition[i]] + 1

    print(prediction_count)
    prediction_count = sorted(prediction_count.items(), key=operator.itemgetter(1), reverse=True)

    return prediction_count[0][0]


# Random Forest for both Training and Testing
def random_forest(bootstrap,query,target_feature):

    feature={}
    tree={}
    result = []
    for i in range(len(bootstrap)):
        feature[i]=bootstrap[i].columns
        feature[i]=list(feature[i])
        feature[i].remove(target_feature)
        c4_5(0,bootstrap[i],feature[i],target_feature,None)     # Train
        tree[i]=root
        result.append(prediction(query, tree[i]))               # Test

    print("Testing ")
    print("Final result : ", majority_voting(result))


# Three bootstrap samples
bootstrap_1=pd.read_csv('bootstrap1.csv')
bootstrap_2=pd.read_csv('bootstrap2.csv')
bootstrap_3=pd.read_csv('bootstrap3.csv')

bootstrap= []
bootstrap.append(bootstrap_1)
bootstrap.append(bootstrap_2)
bootstrap.append(bootstrap_3)


# Query is a testing instance of main data table
query = [['rarely', 'False', 'True', 'yes']]
query = pd.DataFrame(query, columns=['Exercise', 'Smoker', 'Obese', 'Family'])
target_feature = 'Risk'

# Training and Testing with Random Forest
random_forest(bootstrap,query,target_feature)


