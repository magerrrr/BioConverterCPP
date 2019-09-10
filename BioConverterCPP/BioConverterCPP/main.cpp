//
//  main.cpp
//  BioConverterCPP
//
//  Created by Kirill on 9/4/19.
//  Copyright © 2019 Kirill. All rights reserved.
//
//defineUnitsMap(<#float mmol_L#>, <#float µmol_L#>, <#float nmol_L#>, <#float pmol_L#>, <#float mg_mL#>, <#float mg_dL#>, <#float mg_L#>, <#float µg_mL#>, <#float µg_dL#>, <#float µg_L#>, <#float ng_mL#>, <#float g#>, <#float IU#>, <#float µIU_mL#>, <#float mIU_L#>)
//
#include <map>
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

enum UnitIndex {
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

typedef map<UnitIndex, float> UnitsMap;

struct Units {
    string message;
    UnitsMap unitsMap;
};

UnitsMap defineUnitsMap(
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
        { UnitIndex::mmol_L, mmol_L },
        { UnitIndex::µmol_L, µmol_L, },
        { UnitIndex::nmol_L, nmol_L, },
        { UnitIndex::pmol_L, pmol_L, },
        { UnitIndex::mg_mL, mg_mL, },
        { UnitIndex::mg_dL, mg_dL, },
        { UnitIndex::mg_L, mg_L, },
        { UnitIndex::µg_mL, µg_mL, },
        { UnitIndex::µg_dL, µg_dL, },
        { UnitIndex::µg_L, µg_L, },
        { UnitIndex::ng_mL, ng_mL, },
        { UnitIndex::g, g, },
        { UnitIndex::IU, IU, },
        { UnitIndex::µIU_mL, µIU_mL, },
        { UnitIndex::mIU_L, mIU_L, },
    };
};

map<Biomarker, Units> initBiomarkersToUnitsMap() {
    return {
        {
            INSULIN,
            ((struct Units) {
                "Insulin",
                defineUnitsMap(6.94e-9, 6.94e-6, 6.945e-3, 6.945, 0.0347, 0.347, 3.47, 3.47, 347, 3470, 3470, 0.0000347, 1, 1, 1)
            })
        },
        {
            GLUCOSE,
            ((struct Units) {
                "Glucose",
                defineUnitsMap(1, 1000, 1000000, 1000000000, 0.180156, 18.0156, 180.156, 180.156, 18015.6, 180156, 180156, 0, 0, 0, 0)
            })
        },
        {
            LDL,
            ((struct Units) {
                "Cholesterol, low-density (LDL) (high level)",
                defineUnitsMap(0.0259, 0, 0, 0, 0.1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0)
            })
        },
        {
            HDL,
            ((struct Units) {
                "Cholesterol, high-density (HDL) (low level)",
                defineUnitsMap(0.0259, 0, 0, 0, 0.1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0)
            })
        },
        {
            TG,
            ((struct Units) {
                "Triglycerides",
                defineUnitsMap(0.0113, 11.2994, 0, 0, 0.1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0)
            })
        },
        {
            CRP,
            ((struct Units) {
                "C-reactive protein",
                defineUnitsMap(0, 0, 9.524, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0)
            })
        },
        {
            HOMOCYSTEINE,
            ((struct Units) {
                "Homocysteine",
                defineUnitsMap(0, 7.397, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0)
            })
        },
        {
            THYROTROPIN,
            ((struct Units) {
                "Thyrotropin (TSH)",
                defineUnitsMap(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1)
            })
        },
        {
            VITAMIN_D,
            ((struct Units) {
                "Vitamin D",
                defineUnitsMap(0, 0, 0.0000000000249, 0.0000000249, 0.0000249, 0.00249, 0.0249, 0.0249, 2.49, 24.9, 24.9, 0.0000000347, 1, 0, 0)
            })
        },
        {
            ZINC,
            ((struct Units) {
                "Zinc",
                defineUnitsMap(1, 1000, 1000000, 1000000000, 0.06538, 6.538, 65.38, 65.38, 6538, 65380, 65380, 0, 0, 0, 0)
            })
        },
        {
            FERRITIN,
            ((struct Units) {
                "Ferritin",
                defineUnitsMap(1, 1000, 1000000, 1000000000, 445, 44504, 445038, 445038, 44503783, 445037828, 445037828, 0, 0, 0, 0)
            })
        },
    };
};

float convert(Biomarker biomarker, UnitIndex convertFrom, UnitIndex convertTo, double value) {
    const auto biomarkersToUnitsMap = initBiomarkersToUnitsMap();
    const Units units = biomarkersToUnitsMap.at(biomarker);
    const auto unitFrom = units.unitsMap.at(convertFrom);
    const auto unitTo = units.unitsMap.at(convertTo);
    
    cout    << "convertFrom: " << (unsigned int)convertFrom << "\n"
            << "convertTo: " << (unsigned int)convertTo << "\n"
            << "unitFrom: " << unitFrom << "\n"
            << "unitTo: " << unitTo << "\n"
            << units.message << "!\n";
    
    return value * unitTo / unitFrom;
};

int main(int argc, const char * argv[]) {
    cout << convert(GLUCOSE, mmol_L, mg_dL, 5.5) << "\n";
    return 0;
}
