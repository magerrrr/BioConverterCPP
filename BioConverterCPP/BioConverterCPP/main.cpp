//
//  main.cpp
//  BioConverterCPP
//
//  Created by Kirill on 9/4/19.
//  Copyright © 2019 Kirill. All rights reserved.
//

#include <iostream>

enum Biomarker{
    INSULIN,
    GLUCOSE,
    LDL,
    HDL,
    TG,
    CRP,
    HOMOCYSTEINE,
    THYROTROPIN,
    VITAMIN_D,
    ZINC,
    FERRITIN
};

double insulin_units[15] = { // index access 0
    0,         // mmol/l // 0
    0,         // µmol/L // 1
    0,         // nmol/L // 2
    6.945,     // pmol/L // 3 // 14 - 140
    0.0347,    // mg/mL  // 4
    0.347,     // mg/dL  // 5
    3.47,      // mg/L   // 6
    0,         //µg/mL   // 7
    0,         //µg/dL   // 8
    0,         //µg/L    // 9
    0,         //ng/mL   // 10
    0.0000347, // g      // 11
    1,         // IU     // 12
    1,         // µIU/mL // 13 // 2.0 - 20
    1          // mIU/L  // 14
};

double glucose_units[15] = { // index access 1
    1,          // mmol/l // 0 // 3.2 - 5.5
    1000,       // µmol/L // 1
    1000000,    // nmol/L // 2
    1000000000, // pmol/L // 3
    0.180156,   // mg/mL  // 4
    18.0156,    // mg/dL  // 5
    180.156,    // mg/L   // 6
    180.156,    // µg/mL  // 7
    18015.6,    // µg/dL  // 8
    180156,     // µg/L   // 9
    180156,     // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double ldl_units[15] = { // index access 2
    0.0259,     // mmol/l // 0 // >4.144
    0,          // µmol/L // 1
    0,          // nmol/L // 2
    0,          // pmol/L // 3
    0.1,        // mg/mL  // 4 // > 160
    1,          // mg/dL  // 5
    10,         // mg/L   // 6
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double hdl_units[15] = { // index access 3
    0.0259,     // mmol/l // 0 // > 1.03
    0,          // µmol/L // 1
    0,          // nmol/L // 2
    0,          // pmol/L // 3
    0.1,        // mg/mL  // 4
    1,          // mg/dL  // 5 // < 40
    10,         // mg/L   // 6
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double triglycerides_units[15] = { // index access 4
    0.0113,     // mmol/l // 0 // 0.14 - 1.82
    11.2994,    // µmol/L // 1
    0,          // nmol/L // 2
    0,          // pmol/L // 3
    0.1,        // mg/mL  // 4
    1,          // mg/dL  // 5 // < 160
    10,         // mg/L   // 6
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double crp_units[15] = { // index access 5
    0,          // mmol/l // 0
    0,          // µmol/L // 1
    9.524,      // nmol/L // 2
    0,          // pmol/L // 3
    0,          // mg/mL  // 4
    0,          // mg/dL  // 5
    1,          // mg/L   // 6 // < 5
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double homocysteine_units[15] = { // index access 6
    0,          // mmol/l // 0
    7.397,      // µmol/L // 1 // 5 - 15
    0,          // nmol/L // 2
    0,          // pmol/L // 3
    0,          // mg/mL  // 4
    0,          // mg/dL  // 5
    1,          // mg/L   // 6 // 0.68 - 2.02
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double thyrotropin_units[15] = { // index access 7
    0,          // mmol/l // 0
    0,          // µmol/L // 1
    0,          // nmol/L // 2
    0,          // pmol/L // 3
    0,          // mg/mL  // 4
    0,          // mg/dL  // 5
    0,          // mg/L   // 6
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    1,          // µIU/mL // 13
    1           // mIU/L  // 14 // Men: 0.5-6 mIU/L, Women: 4-5 mIU/L
};

double vitaminD_units[15] = { // index access 8
    0,          // mmol/l // 0
    0,          // µmol/L // 1
    0,          // nmol/L // 2
    0,          // pmol/L // 3
    0.0000249,  // mg/mL  // 4
    0,          // mg/dL  // 5
    0,          // mg/L   // 6
    0,          // µg/mL  // 7
    0,          // µg/dL  // 8
    0,          // µg/L   // 9
    0,          // ng/mL  // 10 // 30 - 60
    0.0000000249,// g     // 11
    1,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double zinc_units[15] = { // index access 9
    1,          // mmol/l // 0 // 10 - 23
    1000,       // µmol/L // 1
    1000000,    // nmol/L // 2
    1000000000, // pmol/L // 3
    0.06538,    // mg/mL  // 4
    6.538,      // mg/dL  // 5
    65.38,      // mg/L   // 6
    65.38,      // µg/mL  // 7
    6538,       // µg/dL  // 8
    65380,      // µg/L   // 9
    65380,      // ng/mL  // 10
    0,           // g     // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double ferritin_units[15] = { // index access 10
    1,          // mmol/l // 0
    1000,       // µmol/L // 1
    1000000,    // nmol/L // 2
    1000000000, // pmol/L // 3
    445,        // mg/mL  // 4
    44504,      // mg/dL  // 5
    445038,     // mg/L   // 6
    445038,     // µg/mL  // 7
    44503783,   // µg/dL  // 8
    445037828,  // µg/L   // 9 // Women:13 - 150, Men 30 - 400
    445037828,  // ng/mL  // 10
    0,          // g      // 11
    0,          // IU     // 12
    0,          // µIU/mL // 13
    0           // mIU/L  // 14
};

double convert(enum Biomarker biomarker, int16_t convertFrom, int16_t convertTo, double value) {
    switch(biomarker) {
        case 0 :
            printf("Insulin!\n" );
            return value * insulin_units[convertTo] / insulin_units[convertFrom];;
            break;
            
        case 1 :
            printf("Glucose!\n" );
            return value * glucose_units[convertTo] / glucose_units[convertFrom];;
            break;
            
        case 2 :
            printf("Cholesterol, low-density (LDL) (high level)!\n" );
            return value * ldl_units[convertTo] / ldl_units[convertFrom];;
            break;
            
        case 3 :
            printf("Cholesterol, high-density (HDL) (low level)!\n" );
            return value * hdl_units[convertTo] / hdl_units[convertFrom];;
            break;
            
        case 4 :
            printf("Triglycerides!\n" );
            return value * triglycerides_units[convertTo] / triglycerides_units[convertFrom];;
            break;
            
        case 5 :
            printf("C-reactive protein!\n" );
            return value * crp_units[convertTo] / crp_units[convertFrom];;
            break;
            
        case 6 :
            printf("Homocysteine!\n" );
            return value * homocysteine_units[convertTo] / homocysteine_units[convertFrom];;
            break;
            
        case 7 :
            printf("Thyrotropin (TSH)!\n" );
            return value * thyrotropin_units[convertTo] / thyrotropin_units[convertFrom];;
            break;
            
        case 8 :
            printf("Vitamin D!\n" );
            return value * vitaminD_units[convertTo] / vitaminD_units[convertFrom];;
            break;
            
        case 9 :
            printf("Zinc!\n" );
            return value * zinc_units[convertTo] / zinc_units[convertFrom];;
            break;
            
        case 10 :
            printf("Ferritin!\n" );
            return value * ferritin_units[convertTo] / ferritin_units[convertFrom];;
            break;
            
        default:
            printf("Incorrect biomarker!\n" );
    }
    return 0;
};
int main(int argc, const char * argv[]) {
    std::cout << convert(GLUCOSE,5,0,160);
    return 0;
}
