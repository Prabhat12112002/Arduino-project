#include <stdio.h>

// Conversion functions
double length_convert(double value, int unit1, int unit2) {
    double units[] = {1.0, 0.001, 0.000621371};
    return value * (units[unit1] / units[unit2]);
}

double mass_convert(double value, int unit1, int unit2) {
    double units[] = {1.0, 0.001, 0.00220462};
    return value * (units[unit1] / units[unit2]);
}

double temp_convert(double value, int unit1, int unit2) {
    if(unit1 == unit2) return value;
    if(unit1 == 0) value = (value * 9/5) + 32;
    if(unit1 == 0 || unit2 == 0) value = ((value - 32) * 5/9) + 273.15;
    if(unit2 == 0) value = (value - 273.15) * 9/5 - 32;
    if(unit2 == 1) value = value - 273.15;
    return value;
}

double time_convert(double value, int unit1, int unit2) {
    double units[] = {1.0, 60.0, 3600.0};
    return value * (units[unit1] / units[unit2]);
}

int main() {
    while(1) {
        printf("Select category (1: length, 2: mass, 3: temperature, 4: time, 0: exit): ");
        int category;
        scanf("%d", &category);

        if(category == 0) break;

        printf("Select input unit (1, 2, 3) and output unit (1, 2, 3): ");
        int unit1, unit2;
        scanf("%d%d", &unit1, &unit2);

        printf("Enter value to convert: ");
        double value;
        scanf("%lf", &value);

        double converted;
        switch(category) {
            case 1: converted = length_convert(value, unit1-1, unit2-1); break;
            case 2: converted = mass_convert(value, unit1-1, unit2-1); break;
            case 3: converted = temp_convert(value, unit1-1, unit2-1); break;
            case 4: converted = time_convert(value, unit1-1, unit2-1); break;
        }

        printf("Converted value: %.2lf\n\n", converted);
    }

    return 0;
}
