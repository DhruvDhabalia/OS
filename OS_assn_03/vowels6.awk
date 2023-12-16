BEGIN {
    num = 0
}

{
    if (!($0 ~ /[aeiou]/)) {
        num++
    }
}

END {
    print "Total number of lines without any vowels:", num
}
