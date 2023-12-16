
function result_compute(english, telugu, maths, science, social)
 {
    total = english + telugu + maths + science + social;
    if (english >= 30 && telugu >= 30 && maths >= 40 && science >= 40 && social >= 40)
     {
        result = "PASS";
    } 
    else
     {
        result = "FAIL";
    }
    return total ":" result;
}


BEGIN {
    FS = ",";
    OFS = ":";
}


{
    student_id = $1;
    student_name = $2;
    telugu_m = $3;
    english_m = $4;
    maths_m = $5;
    science_m = $6;
    social_m = $7;


    final_result = result_compute(english_m, telugu_m, maths_m, science_m, social_m);


    print student_id, student_name, final_result;
}
