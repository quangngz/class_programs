# Version Control

- A systematic way to manage concurrent versions of software artefacts 

### git
- A distributed version control system, created by Linus Torvalds, and is probably the most used modern system. 
- repository: A collection of files stored by the version control system. 
- Remote repository: A repository stored in a remote server. 
- Local repository: A repository maintained in the lcoal directory. 
- Index (Staging area): A conceptual place for staging the changes - in .git sub directory. 


### git branching
- Master: The current "known good" code base
- Branch: a version of the codebase being worked on. 
- Commit: a snapshot of a branch. 

### merging
- Incorporating the changes in one branch to another. 
- Merge request: 

GitLab server is used for this subject, and must use `https://swen20003.eng.unimelb.edu.au/.` this repository and nothing else. 

- Git will be used through the command line interface (CLI). 

## Using git

0. Install Git on the local machine. (There's documentation on the Internet)
1. Get the remote repository URL: 
2. Make a local copy of the repository, i.e. clone it through `git clone`
3. Stage all the files via `git add [file name]`
4. `git commit -m "message"` to commit current changes to local repository. 
5. `git push -u origin master` to push it onto the remote repository. 

### Other useful commands: 
`git log` to shows how the files have been modified. 

`git branch` to show the current branch you are in. 

`pull` vs `fetch`
# Build management with Maven

Build management tool, are tools that automate the process of building (compiling) software. (like Make)

This is particularly useful when your Java program is using many 3rd party softwares. 

## Maven
It's a popular build management tool. 

The project structure and contents are declared inside an xml file, i.e. Project Object Model POM file. - pom.xml

This is practice in Workshop 4 (Week 5)

# Intellj Debugger
We all know what debugger is. 

- Watch Expression
- Step over
- Step into / step out of

# Bagel
Basic Academic Graphical Engine Library, developed by the school. 

It's a graphic package. 

IT's important to learn this library to o the project. 

Theres a documentation of this library on the Internet, and on LMS. 
