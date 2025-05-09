/*************************************************************************************
 * File: benchy.h
 * Author: Kyle Bueche
 * 
 * Simple benchmarker for statistical comparison of the runtime of multiple functions
 * 
 * Proper use looks like:
 * benchy.nameFunction("blah blah 1");
 * for (int i = 0; i < 100000; i++) { myFunction }; <-- Warmup
 * for (int t = 0; t < trials; t++) {
 *   benchy.startTrial();
 *   for (int i = 0; i < 100000; i++) { myFunction }; <-- Real Test
 *   benchy.endTrial();
 * }
 * benchy.nextFunction();
 * benchy.nameFunction("blah 2");
 * for (int i = 0; i < 100000; i++) { otherFunction }; <-- Warmup
 * for (int t = 0; t < trials; t++) {
 *   benchy.startTrial();
 *   for (int i = 0; i < 100000; i++) { otherFunction }; <-- Real Test
 *   benchy.endTrial();
 * }
 * benchy.computeStatistics();
 * benchy.outputCSV();
 *********************************************************************************/

#ifndef BENCHY_H
#define BENCHY_H

struct BenchySampleData
{
    std::vector<float> trialTimes;
    float mean;
    float standardDeviation;
    float variance;
}

class benchy
{
    public:
        benchy();
        void nameFunction(char * functionName);
        void startTrial();   // Start benchmarking the current trial
        void endTrial();     // End benchmarking and record the current trial
        void nextFunction(); // Move onto a function to bench
        void computeStatistics();
        void outputCSV();

    private:
        std::vector<BenchySampleData> functions;
        float startTime;
        float endTime;
};


#endif
