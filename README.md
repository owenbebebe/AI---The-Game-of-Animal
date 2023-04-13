<h1>AI - The Game of Animal</h1>

<h2>Description</h2>
I designed and developed a C++ program that implements the "intelligent" guessing game of animals. The program uses a database of animals and starts with only two animals- a shark and a horse. It then asks the user a series of yes-or-no questions to narrow down the type of animal the user is thinking of. If the computer guesses incorrectly, it asks the user for a new question to add to its database to distinguish the user's animal from the incorrect guess. The computer intelligently places this question where it makes sense.

To implement the program, I created a class hierarchy, including a base class and derived classes for nodes and trees. The program uses a tree data structure to represent the database of animals and their characteristics. The nodes in the tree represent the yes-or-no questions, and the leaves represent the animals. The program allows the user to play multiple games, and the computer learns from its mistakes for subsequent games within the same run of the program.

Additionally, the program has a way to "save" the database as a text file, which allows the user to start from an old database or start fresh with the default shark and horse options. The program is intelligently designed to set up the space for easy search based on the user's answers to given questions.

To demonstrate the functionality of the program, I included a sample database of at least ten animals in the source files for the project. Overall, my program effectively implements the "intelligent" guessing game of animals and provides an intuitive user experience.
<br />


<h2>Languages and Utilities Used</h2>

- <b>C++</b> 

<h2>Environments Used </h2>

- <b>Windows 10</b> (21H2)

<h2>Program walk-through:</h2>

<p align="center">
<br />
Loading the Database:  <br/>
<img src="https://i.imgur.com/ow05yHy.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
<br />
The database is a txt file that reads in a series of questions and the program would parse the questions and create a tree structure out of it.
The database is called animalkingdom in this case
<br />
<br />
What the database looks like:  <br/>
<img src="https://i.imgur.com/wWee8nX.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
<br />
As you can see the database is a seris of question followed by 1 and 0, 1 means yes and 0 means no.
The program would read the questions and parse it in a preorder Depth First Traveresal order.
<br />
<br />
Guessing the animal: <br/>
<img src="https://i.imgur.com/z9hGxro.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
<br />
Once we have the database inputed, the machine is going to ask us a series of questions to guess our animal.
The animal I was thinking was lion, and the machine guessed it right!
<br />
<br />
Fail to guess the animal <br/>
<img src="https://i.imgur.com/X6IatGd.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
<br />
Let's try a case where the machine could not get the correct animial!
<br />
In this case we are thinking about jellyfish. The machine eventually failed to identify the animal, and asked us to insert jellyfish into the database. 
<br /> 
It asks for the chracteristic about the jellyfish too, so the machine creates two nodes
<br /> 
One with the chracteristic, and one with the question asking "is your animal jellyfish?"
<br />
Then, we insert the two nodes into the leaf node that we just left off.
<br />
<br />
Export the database with jellyfish in it:  <br/>
<img src="https://i.imgur.com/EkmwM61.png" height="80%" width="80%" alt="Disk Sanitization Steps"/>
<br />

<!--
 ```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ text in purple (and bold)@@
```
--!>
