## Branch Movement
* *git branch* => list branches 
* *git branch <branch_name>* => create branch

* *git checkout <branch_name>* => checkout branch
    
* *git checkout -b <branch_name>* => create and checkout branch
    
* *git push -u origin <branch_name>* =>
 * Set upstream branch for a new remote branch
 * branch_name will be available remotely
 * branch_name can be replaced with HEAD if remote name is space
* *git branch -vv* (checks if there is a remote tracking branch)

* *git -u origin <branch_name>* => set upstream branch for an existing remote branch


* *git checkout --track origin/dev* => 
 * set tracking branches for new local branches
 * dev is the existing remote tracking branch

* *git branch -u origin/<branch_name>* => set tracking branches for existing local branches
    

## Merge
* *git merge <branch_name>* => merge *branch_name* to this branch
 * must be checkout to this branch
* *git diff* => shows the difference if there is conflict

## Resetting 
* *git reset <commit_hash>* => resets to the given has
* *git reset HEAD* => resets to the HEAD
* *git reset HEAD^* => resets to the  commit before HEAD

* *git reset --soft <commit_hash>* => any changes above this hash is not touched and will be waiting to be "committed"
* *git reset --hard <commit_hash>* => any changes above this hash is discarded, not in the stage of track or commit
* *git reset --hard HEAD@{1}* => undo a hard reset


## Deletion
* *git branch -d localBranchName* => Delete local branch
* *git branch -D localBranchName* => Delete local branch that is unmerged 
* *git push -d origin <branch_name>*  => delete remote branch

## Multiple Remote trackers
* *git remote add <name> <url>* => *name* is *origin* for the default one
* *git push <name> <branch_name>* => push the *branch_name* branch to the *name* tracker
* *name* is *origin* and *branch_name* is the *--set-upstream* for the default cases
* *git push --set-upstream <name> <branch_name>* to make *name* and *branch_name* the default ones

## Config
*  *git config --global alias.<alias_name>* "alias body" => Define alias
* *git config — global user.name* => check name
*git config — global user.email* => check email
* *git config — global user.name* = "name" => set  name
* *git config — global user.email* = "email" => set email


## Basics
* *git init* => Initialize a git repository 
* *git stash* => save changes that you don’t want to commit immediately. 
* *git apply* => to bring your saved changes back.

## Routine to avoid conflict from remote branch
* We have to follow this routine for every commit and push we make, so we can avoid frustrating conflicts:
Let’s assume we have made changes to a secondary branch A (not main):
add
switch to main
go to Github and see if the other person (s) made any push:
if yes:
come to local main and do a pull
switch to branch A
commit and push branch A
switch to local main
merge branch A to main
push local main to remote main
if no:
come to local main (NO need to pull)
switch to branch A
commit and push branch A
switch to local main
merge branch A to main
push local main to remote main
Same procedure to be followed for the subsequent changes to the branch A or another secondary branch.


## Learn Markdown
* [Force Directed Graph Tutorial](/https://www.youtube.com/watch?v=y7DxbW9nwmo&t=4998s)

