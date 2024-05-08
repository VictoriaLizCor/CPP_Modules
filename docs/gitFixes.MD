
# Divergent branches 
The `git pull` command options `--rebase`, `--no-rebase`, and `--ff-only` affect
how Git handles divergent branches:

1. `git pull --rebase`: Replays your local commits on top of remote changes.
   This creates a linear commit history but modifies the existing history.
	(*NOTE: Primarily use when changes are in local repo)
2. `git pull --no-rebase`: Merges remote changes into your local branch,
   creating a new merge commit. This maintains the exact commit history but can
   lead to a non-linear history.

3. `git pull --ff-only`: Only allows fast-forward merges. Git moves the branch
   pointer forward to catch up with the remote branch. If a fast-forward merge
   is not possible, the pull operation fails. This maintains a linear commit
   history and doesn't modify the existing history, but doesn't allow divergence
   between local and remote branches.

# Creating new branches
To create a new branch from another branch in Git, you first need to switch to
the branch you want to base your new branch on using the `git checkout` command.
After that, you can create the new branch. Here's how you can do it:

```bash
git checkout existing-branch-name
git branch new-branch-name
git checkout new-branch-name
```

Alternatively, you can create and switch to the new branch in a single command
using the `-b` option with the `git checkout` command:

```bash
git checkout -b new-branch-name existing-branch-name
```

Replace `existing-branch-name` with the name of the branch you want to base your
new branch on, and `new-branch-name` with the name you want to give to your new
branch.

# Merge branches

## Switch to the branch you want to merge into (for example, master)
```bash
git checkout master
```
## Merge the other branch into your current branch (for example, branch-to-merge)
```bash
git merge branch-to-merge
```
# Delete the merged branch locally
```bash
git branch -d branch-to-merge
```
# Delete the merged branch remotely
```bash
git push origin --delete branch-to-merge
```
# Rename branch

To rename a branch in Git, you can use the following commands:

```bash
# Switch to the branch you want to rename
git checkout old-branch-name

# Rename the branch
git branch -m new-branch-name
```

Please replace `old-branch-name` and `new-branch-name` with your actual branch names.

If you want to rename the branch while you are on a different branch, you can do so with the following command:

```bash
git branch -m old-branch-name new-branch-name
```

After renaming, if you have already pushed the branch to the remote, you need to delete the old branch and push the new one:

```bash
# Delete the old branch on remote
git push origin --delete old-branch-name

# Push the new branch to remote
git push origin new-branch-name
```

Again, replace `old-branch-name` and `new-branch-name` with your actual branch names.