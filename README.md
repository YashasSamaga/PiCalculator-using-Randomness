# PiCalculator-using-Randomness
This program uses probability to approximately calculate the value of pi.

If you pick any two random numbers, the probability of the pair of numbers being coprime is given by:

![6/pi^2](http://i.imgur.com/MVWyfYx.png)

This program generates random numbers and calculates the experimental probability. Substituting the experimental value in the aforementioned equation, the value of pi can be approximately calculated. The above method requires that the range of random numbers extends from zero till infinity. However, due to practical limitations, we will use a range up to the largest number the computer can process. Also note that the larger the number of trials, the more accurate the calculated value of pi will be.
