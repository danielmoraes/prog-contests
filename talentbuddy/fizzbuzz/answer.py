# Talent Buddy
# FizzBuzz
# Author: Daniel Moraes (daniel.b.moraes@gmail.com)

def fizzbuzz(n):
   for i in xrange(1, n + 1):
        print "Fizz" * (i % 3 == 0) + "Buzz" * (i % 5 == 0) or i

fizzbuzz(15)
