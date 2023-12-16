


function raiseto(n) {
    if (n == 0) {
        print "0 to the power of 0 is undefined."
    } 
    if (n == 1){
        return 1
    } 
    else {
        return n ^ n
    }
}


{
    number = $1
    ans = raiseto(number)
    if (number != 0){
        print number, "to the power of", number, "is", ans
    }    
}


BEGIN {
    print "Result of date command execution"
    system("date")
}
