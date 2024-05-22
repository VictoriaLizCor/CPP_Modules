
# Divergent branches 
<!--
 Safest option:
	hint:   git config pull.rebase false  # merge (the default strategy)
#hint:   git config pull.rebase true   # rebase
#hint:   git config pull.ff only       # fast-forward only
-->
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
# git checkout -b cpp01ex03-003 $(git branch --show-current) 

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
## Change merge default message
```bash
git merge --edit branch-to-merge
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
If you want to rename the branch while you are on a different branch, you can do so with the following command:

```bash
git branch -m old-branch-name new-branch-name
```

## Delete and rename remote branch 
1. Delete the old-name remote branch and push the new-name local branch:

```bash
git push origin :old-name new-name
```

Reset the upstream branch for the new-name local branch:

```bash
git push origin -u new-name
```
2. Another option is 
```bash
# Delete the old branch on remote
git push origin --delete old-branch-name

# Push the new branch to remote
git push origin new-branch-name
```
# Commit : Amend previous message

The `git commit --amend` command is used to modify the most recent commit. It doesn't work for commits that are not the latest. If you want to modify a commit that is not the latest, you can use an interactive rebase.
<!--git commit --amend --no-edit -->

```bash
git push origin --force-with-lease $(git branch --show-current)
```
Here's how you can do it:

```bash
git rebase -i HEAD~3
```

This command will open a text editor with a list of the last 3 commits. Each commit is represented by a line that starts with the word `pick`.

To modify a commit, replace `pick` with `edit` for that commit. Then save and close the editor.

Git will now pause the rebase at the commit you want to edit. You can amend the commit as you want. For example, you can modify the files or use `git commit --amend` to change the commit message.

Once you're done, you can continue the rebase with:

```bash
git rebase --continue
```

Please note that this will rewrite the commit history, which can cause problems for others if they have cloned or pulled your repository. Be careful when using `git rebase`.

# Add commit template to local repository
```bash
git config --local commit.template {path-to-commit-template}
```
# Adding SUBMODULES:

GitHub Copilot: To add a submodule to a Git project, you can use the `git submodule add` command. Here's how you can do it:

1. Navigate to your project directory in the terminal.

```bash
cd /path/to/your/project
```

2. Add the submodule. Replace `https://github.com/username/repo.git` with the URL of the repository you want to add as a submodule.

```bash
git submodule add https://github.com/username/repo.git
```

By default, the submodule will be added in a directory named after the repository. If you want to add it in a different directory, you can specify the path as a second argument:

```bash
git submodule add https://github.com/username/repo.git path/to/submodule
```

3. Commit and push the changes.

```bash
git commit -m "Added submodule"
git push
```

Now, the submodule is added to your project. When you clone the project, use the `--recursive` option to also clone all submodules:

```bash
git clone --recursive https://github.com/yourusername/yourproject.git
```

If you've already cloned the project and want to fetch the submodules, you can use the `git submodule update` command:

```bash
git submodule update --init --recursive
```
