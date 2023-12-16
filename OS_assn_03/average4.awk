

BEGIN {
    FS = ","
    total = 0
    num = 0
}

{
    if (NF >= 4) {
        print $1, $4
        total += $4
        num++
    }
}

END {
    if (total > 0) {
        avg = total / num
        print "Average of 4th fields of entire data:", avg
    } else {
        print "No valid records found."
    }
}
