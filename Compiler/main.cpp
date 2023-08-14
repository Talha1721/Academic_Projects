#include <bits/stdc++.h>


using namespace std;

bool iscontain(vector <string> v, string s)
{
    int i=0;
    string s1;
    while(i<v.size())
    {
        s1=v.at(i);
        i++;
        if(s.compare(s1)==0)
        {
            return 1;
        }
    }
    return 0;

}

int isSubstring (string s1, string s2)
{
    int i=0,j=0;
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for ( i = 0; i <= abs(N-M); i++)
    {


        /* For current index i, check for pattern match */
        for (j = 0; j < N; j++)
            if (s1[i + j] != s2[j])
                break;

        if (j == N)
            return i;
    }

    return -1;
}

bool isnum(string s)
{
    int i=0;
    while(i<s.length())
    {
        if(!(s[i]>='0' && s[i]<='9') && s[i]!= '.')
        {
            return 0;
        }
        i++;
    }
    if(i==s.length())
    {
        return 1;
    }
}

bool isvariable(string s)
{
    int i=0;
    if(!(s[0]>='0' && s[0]<='9'))
    {
        return 1;
    }

    return 0;
}

int ischecking (string s)
{
    vector<string> reserved, operato, bracket,token,declared,f;
    reserved.push_back("int");
    reserved.push_back("float");
    reserved.push_back("char");
    reserved.push_back("double");
    reserved.push_back("if");
    reserved.push_back("for");
    reserved.push_back("else");
    reserved.push_back("while");
    reserved.push_back("do");
    reserved.push_back("break");
    reserved.push_back("continue");
    reserved.push_back("return");


    operato.push_back("+");
    operato.push_back("-");
    operato.push_back("*");
    operato.push_back("/");

    bracket.push_back("(");
    bracket.push_back(")");
    bracket.push_back("{");
    bracket.push_back("}");
    bracket.push_back("[");
    bracket.push_back("]");

    if(s.compare("int")==0 || s.compare("float")==0 || s.compare("double")==0 || s.compare("char")==0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    ///in ischecking function 1 for data type.
    ifstream file;
    string line,s="",arrsize="",pretoken="",present_token="";
    int pointer=0,isfor=0,iswhile=0;
    int back,i,j,semicolon=0,b=0,fun=0,r=0, a [4], comment=0,l ;
    stack<char> st;
    vector<string> reserved, operato, bracket,token,declared,f,datatype;
    reserved.push_back("int");
    reserved.push_back("float");
    reserved.push_back("char");
    reserved.push_back("double");
    reserved.push_back("if");
    reserved.push_back("for");
    reserved.push_back("else");
    reserved.push_back("while");
    reserved.push_back("do");
    reserved.push_back("break");
    reserved.push_back("continue");
    reserved.push_back("return");

    datatype.push_back("int");
    datatype.push_back("float");
    datatype.push_back("double");
    datatype.push_back("char");

    operato.push_back("+");
    operato.push_back("-");
    operato.push_back("*");
    operato.push_back("/");

    bracket.push_back("(");
    bracket.push_back(")");
    bracket.push_back("{");
    bracket.push_back("}");
    bracket.push_back("[");
    bracket.push_back("]");

    file.open("compiler.txt");
    l=0;
    while(!file.eof())
    {
        s="";
        getline(file, line);
        // cout << line << " \n";
        l++;
        i=0,j=0;
        while(i<line.length() )
        {

        ///detecting the starting of multiple line comment
            if((line[i]=='/' && line[i+1]=='*') || comment==1)
            {
                comment=1;
                while(i<line.length())
                {
                    if(line[i]=='*' && line[i+1] == '/')
                    {
                        comment = 0;
                        i++;
                    }
                    i++;
                }
            }
            /*if(line[i]==' ' && r==0)
            {
                i++;
                continue;
            }*/

            if(comment==0)
            {
                if(isfor==1)
                {

                }
                ///single line comment
                if( line[i] == '/' && line[i+1] == '/' )
                {
                    break;
                }
                 if(( pretoken.compare("while")==0 || pretoken.compare("for")==0 || pretoken.compare("if")==0) && line[i]!='(')
                {
                       cout << "expected (.\n" ;
                       pretoken=line[i];
                }
                ///function starting detect
                if(isfor==1 && line[i]==';')
                {
                    semicolon++;

                }
                if(line[i] == '(' && iscontain(reserved,s) ==0 && s.compare("")!=0)
                {
                    cout << s << " is a function.\n";
                    fun=1;
                    b=0;
                    //i++;
                   // s="";
                    // continue;
                }
                if(line[i] == ')')
                {
                    fun=0;
                    // s="";
                    // i++;
                    // continue;

                }
                if(line[i]=='('  )
                {
                    if(pretoken.compare("while")==0)
                    {
                        st.push('w');
                    }
                    else if(pretoken.compare("for")==0)
                    {
                        st.push('f');
                    }
                    st.push(line[i]);
                    cout  << line[i] << " is an opening bracket.\n";

                }
                else if(line[i]== '{')
                {
                    st.push(line[i]);
                     cout  << line[i] << " is an opening bracket.\n";

                }
                else if(line[i]=='[')
                {
                    st.push(line[i]);
                     cout  << line[i] << " is an opening bracket.\n";

                }
                else if(line[i]==')' && st.empty()==0 && st.top()=='(')
                {
                    st.pop();
                     cout  << line[i] << " is a closing bracket.\n";
                     if(st.empty()==0 && st.top()=='w')
                     {
                         st.pop();
                         cout << "End of while.\n";
                         iswhile=0;
                     }
                     else if(st.empty()==0 && st.top()=='f')
                     {
                         if(semicolon!=2)
                         {
                             cout << "; expected.";
                         }
                         st.pop();
                         cout << "End of for.\n";
                         isfor=0;

                     }

                }
                else if(line[i]=='}' && st.empty()==0 && st.top()=='{')
                {
                    st.pop();
                     cout  << line[i] << " is a closing bracket.\n";

                }
                else if(line[i]==']' && st.empty()==0 && st.top()=='[')
                {
                    st.pop();
                     cout  << line[i] << "\n";

                }
                else if(line[i]==']' || line[i]=='}' || line[i]==')')
                {
                    cout << "Unexpected " << line[i] << ".\n";
                }
                ///string collect
                if(!( line[i]==' ' ||  line[i]==',' || line[i]==';'|| line[i]=='{' || line[i]=='}' || line[i]=='(' || line[i]==')' || line[i]=='=' || line[i]=='<' || line[i]=='>' || line[i]=='+' || line[i]=='-') )
                {
                    /// pointer check
                    if(line[i]=='*' && b==1)
                    {
                        pointer=1;
                        i++;
                        continue;
                    }
                    s+=line[i];
                   // if(i<line.length() && !(line[i+1]!=',' && line[i+1]!=';' && line[i+1]!='+' && line[i+1]!='-' && line[i+1]!='*' && line[i+1]!='/' && line[i+1]!='%'))
                    i++;
                    if(i!=line.length() )
                        continue;
                }


                ///string detect
                if((line[i]==' ' || line[i]==')' || line[i]=='(' || line[i]==',' || line[i]==';' || line[i] == '=' || line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i]=='/' || line[i] == '%' || line[i]=='[' || line[i]==']') || i>= line.length() )
                {

                    if(r==1 && line[i]==';')///r means return
                    {
                        r=0;
                        cout << "The function returns "<< s << "\n";
                        pretoken=s;
                        i++;
                        continue;
                    }

                    if(r==1)
                    {
                        i++;
                        continue;

                    }


                    ///if the variables are declared or not
                    if(b==0 && s.compare("") !=0 && s.compare("return")!=0)
                    {

                        b= ischecking(s);
                        if(b==1)
                        {
                            cout << s << " is a data type.\n";
                           // s="";
                        }
                        else if(s[0]=='&')
                        {
                            string s10="";
                            for(int ac=1; ac<s.length(); ac++)
                            {
                                s10+=s[ac];
                            }
                            if(iscontain(declared,s10)==1)
                            {
                                cout << s << " is address of " << s10 << ".\n";
                            }
                        }
                        else if(isnum(s)==1)
                        {
                            cout << s << " is a value.\n";
                            s="";
                        }
                        else if(iscontain(declared,s)==1)
                        {

                            cout << s << " is a declared variable.\n";
                            s="";
                        }
                        else if(fun!=1 && iscontain(reserved,s)==0 && iscontain(operato,s)!=-1 && isSubstring(s,"+")==-1 && isSubstring(s,"-")==-1 && isSubstring(s,"*")==-1 && isSubstring(s,"/")==-1 && isSubstring(s,"%")==-1 && isSubstring(s,">")==-1 && isSubstring(s,"<")==-1 && isSubstring(s,"=")==-1)
                        {
                            cout << s << " is not declared.\n";
                            s="";
                        }
                        //s="";
                    }


                    ///variable declarartion and validation
                    if(b==1 && s.compare("")!= 0 && iscontain(datatype,s)==0)// && iscontain(operato,s)!=0 && iscontain(bracket,s)!=0)
                    {

                        while(line[i]==' ')
                        {
                            i++;
                        }
                        if(line[i]=='[' || (isSubstring(s,"[")!=-1 && isSubstring(s,"]")==-1))
                        {
                            if(line[i]!= ' ')
                                s+=line[i];
                            // i++;
                            while(line[i]!=']' && i<line.length() )
                            {
                                i++;
                                if(line[i]!=' ')
                                {
                                    //  arrsize+=line[i];
                                    s+=line[i];
                                }
                                if(line[i]==']')
                                {
                                    st.pop();
                                    cout << "] is a closing bracket.\n";
                                }

                            }
                            // s+=line[i];
                        }
                        if(isSubstring(s,"[")!=-1 && isSubstring(s,"]"))
                        {
                            int z;
                            string ss="";
                            int y=isSubstring(s,"[");
                            for( z=0; z<y; z++)
                            {
                                ss+=s[z];
                            }
                            z++;
                            while(s[z]!=']' && z<s.length())
                            {
                                if(s[z]!=' ')
                                {
                                    arrsize+=s[z];
                                }
                                z++;
                            }
                        }
                        if(s.compare("*") == 0)
                        {
                            pointer=1;
                            s="";
                            while(!(line[i]== ';' || line[i] == ',' || line[i]==' '))
                            {
                                s+=line[i];
                                i++;
                            }
                        }
                        if(iscontain(reserved,s)==1)
                        {
                            cout << s << " is an invalid variable.\n";
                            s="";
                        }
                        else if(isnum(s)==1)
                        {
                            cout << s << " is a value.\n";
                        }
                        else if(isvariable(s) == 0)
                        {
                            cout << s << " is an invalid variable.\n" ;
                            s="";
                        }
                        else if(pointer==1)
                        {
                            pointer=0;
                            cout << s << " is a pointer variable.\n";
                            declared.push_back(s);
                        }
                        else if(isSubstring(s,"[")!=-1 )
                        {
                            int z;
                            string ss="";
                            int y=isSubstring(s,"[");
                            for( z=0; z<y; z++)
                            {
                                ss+=s[z];
                            }
                            z++;
                            /*
                            while(z<s.length() && s[z]!=']')
                            {
                                if(s[z]!=' ')
                                {
                                    arrsize+=s[z];
                                }
                                z++;
                            }
                            */
                            cout << ss << " is an array of size " << arrsize <<".\n";
                            arrsize="";
                            declared.push_back(ss);
                        }
                        else
                        {

                            cout << s << " is a variable.\n";
                            declared.push_back(s);
                        }
                        // i++;
                        // s="";
                        // continue;
                    }
                    //if(line[i-1]==' ') continue;
                }


                if(s.compare("return")==0)
                {
                    r=1;
                    pretoken=s;
                   // s="";
                }
                if(s.compare("if")==0)
                {
                    cout << s << " is a conditional keyword.\n";
                    pretoken=s;
                    iswhile=1;
                   // s="";
                }
                if(s.compare("for")==0 || s.compare("while")==0)
                {
                    if(s.compare("for")==0)
                    {
                        isfor=1;
                    }
                    else
                    {
                        iswhile=1;
                    }

                    /* if(s.compare("for")==0)
                     {
                         isfor=1;
                     }
                     else
                     {
                         iswhile=1;
                     } */
                    while(line[i]==' ' && i<line.length())
                    {
                        i++;
                    }
                    i--;
                    cout << s << " is a loop\n";
                    pretoken=s;
                   // s="";
                }
                if(line[i]==';')
                {
                    //i++;
                    if(b==1)
                    {
                        b=0;
                    }
                    // continue;
                }

                if(line[i] == '=' && line[i+1] == '=')
                {
                    i++;
                    cout << "== is a comparative operator.\n";
                }
                else if(line[i] == '=')
                {
                    cout << "= is an assignment operator.\n";
                }
                if(line[i] == '>' && line[i+1] == '=')
                {
                    i++;
                    cout << ">= is a comparative operator.\n";
                }
                else if(line[i] == '>')
                {
                    cout << "> is an comparative operator.\n";
                }
                if(line[i] == '<' && line[i+1] == '=')
                {
                    i++;
                    cout << "<= is a comparative operator.\n";
                }
                else if(line[i] == '<')
                {
                    cout << "< is an comparative operator.\n";
                }
                else if(line[i] == '+' && line[i+1] == '+')
                {
                    i++;
                    cout << "++ is an incremental operator.\n";
                }
                else if(line[i] == '-' && line[i+1]=='-')
                {
                    i++;
                    cout << "-- is a decremental operator.\n";
                }
                else if(line[i]== '+' || line[i] == '-')
                {
                    cout << line[i] << " is an operator.\n";
                }
                i++;

                pretoken=s;
                s="";
            }
        }


    }

    while(st.empty()==0)
    {
        char c1=st.top();
        cout << "closing bracket expected. " << c1;
        st.pop();
    }
    file.close();

    cout<<"\n\n<---------------------------- Symbol Table ----------------------------->\n"<<endl;
    cout<<" ---------------------------------------------------------------------- "<<endl;
    cout<<" |   Lexeme"<<"  |      "<<"Token Type"<<"     |  "<<"Pointer to symbol table entry  |"<<endl;
    cout<<" ---------------------------------------------------------------------- "<<endl;

    int k;
    for( k=0;   k<declared.size() ;   k++ )
    {
        cout<<" |     "<< declared.at(k) <<"     |        <id,"<< k<< ">"<<"       |                "<< k <<"                |\n";
        cout<<" ---------------------------------------------------------------------- "<<endl;

    }


    return 0;
}
