# Benchmarker

## Typical usage:
```cpp
int main()
{
  int warmupIterations = 1000000;
  int iterations = 1000000;
  int problemSizeMax = 1000000;
  Benchy benchy = Benchy();

  // Output statistics for one function
  myFunctionWithAHotLoop(warmupIterations);
  benchy.start();
  myFunctionWithAHotLoop(iterations);
  benchy.end();
  benchy.print();

  // Output comparison statistics for two functions, including stdev

  // Measure apparent algorithmic complexity
  for (int i = 0; i < problemSizeMax; i++)
  {
    benchy.startPlot(i);
    myFunctionWithAHotLoop(i);
    benchy.endPlot(i);
  }

  // Computes a regression function for each typical complexity case.
  // Chooses the function with the least final error.
  benchy.printPlotComplexity();

}
