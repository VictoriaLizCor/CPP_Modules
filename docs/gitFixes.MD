
# Divergent branches 
The `git pull` command options `--rebase`, `--no-rebase`, and `--ff-only` affect
how Git handles divergent branches:

1. `git pull --rebase`: Replays your local commits on top of remote changes.
   This creates a linear commit history but modifies the existing history.

2. `git pull --no-rebase`: Merges remote changes into your local branch,
   creating a new merge commit. This maintains the exact commit history but can
   lead to a non-linear history.

3. `git pull --ff-only`: Only allows fast-forward merges. Git moves the branch
   pointer forward to catch up with the remote branch. If a fast-forward merge
   is not possible, the pull operation fails. This maintains a linear commit
   history and doesn't modify the existing history, but doesn't allow divergence
   between local and remote branches.
