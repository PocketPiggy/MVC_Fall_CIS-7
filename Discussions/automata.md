Out of all of the provided options, I feel like the Finite State Machine appeals
to me the most. I'm not really an expert at this personally, but I have
programmed an example once in Javascript as a proof of concept without
understanding the underlying concepts. Upon researching the FSM, I've come to
understand what was abstracted from me when I wrote that code. The gist of it is
that an FSM will take in some inputs, change to a different state, and depending
on the current state, may switch depending on the input taken.

A common interview task I've found for entry level developers (outside of
leetcode DS&A) is to create a FSM, usually something simple like a stoplight.
Managing state is quite important, as when it comes to actual computing and
business logic, state matters quite a lot with many moving parts. A neat way to
think about it is to map it out, like on a table to see which particular input
will go to a certain output.

It's exciting to see FSA used in things like computational linguistics, as
linguistics & CS is something I'm interesting majoring in. I was a little
surprised to see how it connects with morphology but in hindsight, it makes
sense, as the morphenes free & bound follow a similar pattern when breaking them
down, as well as Natural language processing. In game development, FSM is also
helpful for determining state of NPCs, PCs, and more. In real life, ATMs,
stoplights, and even parking meters utilize this design pattern.



https://gameprogrammingpatterns.com/state.html
https://cs.union.edu/~striegnk/courses/nlp-with-prolog/html/node2.html#l1.fsas
https://web.stanford.edu/class/linguist139p/Slides.pdf
https://rosettacode.org/wiki/Finite_state_machine
