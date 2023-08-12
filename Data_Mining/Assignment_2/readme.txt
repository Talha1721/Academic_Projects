               
                                   +==============================+                  
                                   +        ABOUT DATASET :       + 
                                   +==============================+
				   +==============================+
                                   +        All Word Number:	  +
                                   +        **  19672266  **	  +
                                   +==============================+
                                   +    Uniq Word/Unigram Number: +
                                   +        **  327501  **        +
                                   +==============================+
                                   +    Unique Bigram Number:     +
                                   +        **  5771290  **       +
                                   +==============================+
                                   +    Unique Trigram Number:    +
                                   +        **  13398832  **      +
                                   +==============================+


                              +=======================================+
                              +        ABOUT FOLDERS AND FILES:       +
                              +=======================================+
                                   
                                                  FOLDERS
      +=======================================================......===============================+
      +        1. Unigram    2. Bigram     3. Trigram                           4. Sentences       +
      +=======================================================......===============================+
                                ||                                                   ||
                                || FILES                                             || FILES
                                ||                                                   ||
                                ||                                                   ||
                                ++                                                   ++
                  1. unique_word_datafile.txt                                 1. All_sentenes.txt
                  2. alphabetically_sorted.txt                                2. trade.txt
                  3. frequency_wise_sorted.txt                                3. quadruple.txt
                  4. histogram.txt                                            4. national.txt
                  5. unigram/bigram/trigram_histogram.png                     5. international.txt
                                                                              6. frontpage.txt
                                                                              7. editorial.txt
                                                                              8. sports.txt
                                
There are four folders named Unigram, Bigram, Trigram and Sentences.

About files of Unigram, Bigram, Trigram folders:

1.unique_word_datafile.txt
->contain two informations-
-> word: each unique unigram/bigram/trigram within whole news file
-> frecuency :numbers of occurance of every unique unigram/bigram/trigram within whole news file

2.alphabetically_sorted.txt
->this is the sorted form of unique_word_datafile.txt file
->sorting is done bengali-alphabet wise
->alphabet wise means first letter of each unique unigram/bigram/trigram

3.frequency_wise_sorted.txt
->this is the another sorted form of unique_word_datafile.txt file
->sorting is performed according to the frequency of each unique unigram/bigram/trigram 
->sorting type is ascending order sorting

4.histogram.txt
->this file contain bengali alphabet 
->and total number of unique unigram/bigram/trigram that start with each bangali alphabet 

5.unigram_histogram.png
->this is the histogram of 
->bengali alphabet and corresponding numbers of unique unigram/bigram/trigram that start with that bengali alphabet 

About files of Sentences folder:
->there are seven files of different catagories of news data 
->each file contains sentences one by one of corresponding catagories of news data
->All_sentences.txt is the merged file of seven different files
