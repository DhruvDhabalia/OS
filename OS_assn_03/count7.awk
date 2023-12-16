BEGIN{
   char_num = 0
   num_of_words = 0
   line = 0
}   

{
    FS = ","
      
    char_num += length;


    num_of_words += NF;


    line++;
}


END {
    print "Number of characters:", char_num;
    print "Number of words:", num_of_words;
    print "Number of lines:", line;
}
