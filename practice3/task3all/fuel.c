int check_fuel(int fuel_level, int max_fuel_level) {
    return fuel_level <= (int)(max_fuel_level * 0.1) ? 0: 1;
}