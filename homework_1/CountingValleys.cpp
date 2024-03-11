int countingValleys(int steps, string path) {
    int sealevel = 0; 
    int valleys = 0; 

    for (char step : path) {
        if (step == 'U') { 
            sealevel++;
        } else if (step == 'D') { 
            sealevel--;
        }

        if (sealevel == 0 && step == 'U') {
            valleys++;
        }
    }

    return valleys;

}
