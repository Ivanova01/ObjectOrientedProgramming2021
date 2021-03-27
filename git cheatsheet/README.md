# git cheat sheet

## git file types
  * blob
  * trees
  * commit
  * annotated tags

## Commands List
 * git init -> create new repo on local
 * git remote add origin "repo url" -> add remote repo after creating local branch
 * git clone "repo url" -> copy repo on local
 * git status
 * git add -A -> add all modified/created/deleted files for the next commit
 * git commit -m"Commit Message" -> create commit on LOCAL
 * git branch -> create new brach at the current commmit
 * git merge "branch name"
 * git log -> show all commits in the current branch's history
 * git fetch -> fetch ALL branches from the server
 * git push -> push all commits on the server
 * git pull -> fetch + merge on the tracking branch
 * git rebase [-i] "branch name" -> rebase on topic branch [interactive]
 * git checkout "branch_name or SHA1" -> switch the HEAD on branch/commit
 * git stash -> stashes all files in the working directory
 * git stash list -> shows a list with all current stashes
 * git stash apply -> tries to apply the most recent stash
 * git stash apply@{"stash index"} -> tries to apply the stash with "stash index" in the stash list
 * git stash clear -> remove all stash entries

## When setting up git for first time
 * git config --global user.name "User Name"
 * git config --global user.email "email"

# Apply git colors in terminals that support it
 * git config --global color.ui auto

## To check all the configs
 * git config --global --list

## When creating new local branch
 * git checkout main
 * git pull
 * git checkout -b "new branch name"

## Commands after making changes
 * git add -A 
 * git commit -m"Commit message"

## When pushing local branch to remote
 * git push -u origin "branch name"
 - or if we work on one branch just
 * git push

## When you want to add your changes to the last commit
 * git commit --amend
 *Note* If you have pushed the commit to origin, then you'll have to make a force push ```git push -f```

## When you want to hard reset a branch to a certain SHA1
 * git checkout "branch to reset"
 * git reset --hard SHA1

## When you want to hard reset a branch to the last commit
 * git checkout "branch to reset"
 * git reset --hard