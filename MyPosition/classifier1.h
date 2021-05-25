#pragma once
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[2] <= -25.0) {
                            if (x[4] <= -80.0) {
                                return 1;
                            }

                            else {
                                return 2;
                            }
                        }

                        else {
                            return 0;
                        }
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* predictLabel(float *x) {
                        switch (predict(x)) {
                            case 0:
                            return "Bathroom";
                            case 1:
                            return "Bedroom";
                            case 2:
                            return "Kitchen";
                            default:
                            return "Houston_we_have_a_problem";
                        }
                    }

                protected:
                };
            }
        }
    }
