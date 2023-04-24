Phase 1:
There are rumors on the internets.

There was a comparison function that took a constant string and compared it to my input. Therefore the inputted string would have to match this constant in order to defuse the bomb.

Phase 2:
1 3 6 10 15 21

This phase looked at a number sequence. The first number was just a guess, but then afterwards I had to do some algebra to figure out the next numbers in the sequence. Every time, the difference between the current number and the next number would increase by 1 from the previous difference. Once you figure out the starting number and difference, the sequence wasn't too bad to figure out.

Phase 3:
Bm$!Aka{gl

This phase obviously had something to do with strings. I attempted a basic test string 'aaaaaa' to see what would happen. It exploded so I continued looking into the assembly. I noticed that it wouldn't get past the first explosion unless the inputted string was a certain length. But then I noticed it compared the string length to 0xa which is 10. I entered in strings of length 10 and sure enough I was able to get past the first explosion.
Then it got bad haha. Well, I was experimenting to see what exactly the listed address next to the string 'Kh. Gibran' would do. Surely enough, it was changing every time I inputted something different which makes sense because that's how addresses be. I also looked into the object the leaq command was associated with but that content would change as well. So that got me thinking about what are the constants in this and that's when I noticed rsp. I converted all of its contents from hex to binary. The resulting xor should be the binary of 'Kh. Gibran' so I just worked backwards.

Phase 4:
2 155

Right off the bat, I noticed that there was a %d %d comment. This got me thinking that this would probably need 2 numbers to work. There's also this scanf function but I think it just scans in the input. I noticed this compare function before the jump that looked at the value eax pointed to, and compared that to 1. That made me think that the first number needed to be 1. I noticed that the bomb will explode if a number is less than 1 because of the jle jump. So the first number can't be negative. And there was also a cmpl for 7, so the first number has to be between 1 and 7. I then realized that these numbers are associated with the starting case that adds or subtracts numbers. I experimented a lot before realizing there were two cmpls which meant that whatever input I put in had to be non-negative and equal to the resulting difference of whatever cases I executed. I also noticed the multiple 696s I had that just canceled each other out, but the last 696 would subtract and go into the negatives. Therefore, I entered in 2 as my input to use +851 to get a net positive from 851-696 = 151. The 151 is the second input.
