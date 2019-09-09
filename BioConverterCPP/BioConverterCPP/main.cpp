//
//  main.cpp
//  BioConverterCPP
//
//  Created by Kirill on 9/4/19.
//  Copyright © 2019 Kirill. All rights reserved.
//

#include <map>
#include <tuple>
#include <iostream>

using namespace std;

enum Biomarker {
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

typedef enum Biomarker Biomarker;

namespace Unit {
    typedef float mmol_L;
    typedef float µmol_L;
    typedef float nmol_L;
    typedef float pmol_L;
    typedef float mg_mL;
    typedef float mg_dL;
    typedef float mg_L;
    typedef float µg_mL;
    typedef float µg_dL;
    typedef float µg_L;
    typedef float ng_mL;
    typedef float g;
    typedef float IU;
    typedef float µIU_mL;
    typedef float mIU_L;
}

enum Units {
    mmol_L,
    µmol_L,
    nmol_L,
    pmol_L,
    mg_mL,
    mg_dL,
    mg_L,
    µg_mL,
    µg_dL,
    µg_L,
    ng_mL,
    g,
    IU,
    µIU_mL,
    mIU_L
};

typedef tuple<
    Unit::mmol_L,
    Unit::µmol_L,
    Unit::nmol_L,
    Unit::pmol_L,
    Unit::mg_mL,
    Unit::mg_dL,
    Unit::mg_L,
    Unit::µg_mL,
    Unit::µg_dL,
    Unit::µg_L,
    Unit::ng_mL,
    Unit::g,
    Unit::IU,
    Unit::µIU_mL,
    Unit::mIU_L
> OrderedUnits;

typedef map<Biomarker, OrderedUnits> BiomarkersToUnitsMap;

OrderedUnits defineUnitsList(
    float mmol_L,
    float µmol_L,
    float nmol_L,
    float pmol_L,
    float mg_mL,
    float mg_dL,
    float mg_L,
    float µg_mL,
    float µg_dL,
    float µg_L,
    float ng_mL,
    float g,
    float IU,
    float µIU_mL,
    float mIU_L
) {
    return {
        mmol_L,
        µmol_L,
        nmol_L,
        pmol_L,
        mg_mL,
        mg_dL,
        mg_L,
        µg_mL,
        µg_dL,
        µg_L,
        ng_mL,
        g,
        IU,
        µIU_mL,
        mIU_L
    };
};

BiomarkersToUnitsMap initBiomarkersToUnitsMap() {
    return {
        {
            INSULIN,
            defineUnitsList(0, 0, 0, 6.945, 0.0347, 0.347, 3.47, 0, 0, 0, 0, 0.0000347, 1, 1, 1)
        },
        {
            GLUCOSE,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            LDL,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            HDL,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            TG,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            CRP,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            HOMOCYSTEINE,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            THYROTROPIN,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            VITAMIN_D,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            ZINC,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
        {
            FERRITIN,
            defineUnitsList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)
        },
    };
};

double convert(enum Biomarker biomarker, Units convertFrom, Units convertTo, double value) {
    BiomarkersToUnitsMap biomarkersToUnitsMap = initBiomarkersToUnitsMap();
    OrderedUnits unitsList = biomarkersToUnitsMap.at(biomarker);
    float unitF = unitsList.get<0>;
   // float unitFrom = OrderedUnits;
//float unitTo = unitsList[convertTo];

    switch(biomarker) {
        case 0 :
            printf("Insulin!\n" );
            
            return value * unitFrom / unitTo;
            break;
/*
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
     */
        default:
            printf("Incorrect biomarker!\n" );
    }
    return 0;
};

int main(int argc, const char * argv[]) {
    cout << convert(GLUCOSE, mmol_L, mg_dL, 160);
    return 0;
}
