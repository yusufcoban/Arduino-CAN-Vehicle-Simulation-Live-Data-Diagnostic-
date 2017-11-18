##List of functions and there respective git commands

| Functions | Git Commands |
|:---|:---|
| init(flagsArray, callback) | git init [flags] |
| initSync(flagsArray) | git init [flags] |
| log(path, callback) | git log [path] |
| logSync(path | git log [path] |
| status(callabck) | git status |
| statusSync() | git status |
| add(fileArray, callback) | git add [files] |
| addSync(fileArray) | git add [files] |
| remove(fileArray, callback) | git rm --cached [files] |
| removeSync(fileArray) | git rm --cached [files] |
| unstage(fileArray, callback) | git reset HEAD [files] |
| unstageSync(fileArray) | git reset HEAD [files] |
| commit(message, callback) | git commit -m 'message' |
| commitSync(message) | git commit -m 'message' |
| getBranches(flagsArray, callback) | git branch [flags] |
| getBranchesSync() | git branch |
| createBranch(name, callback) | git branch [name] |
| createBranchSync(name) | git branch [name] |
| checkout(branch, flags, callback) | git checkout [flags] [branch] |
| checkoutSync(branch) | git checkout [branch] |
| merge(branch, callback) | git merge [branch] |
| mergeSync(branch) | git merge [branch] |
| getTags(callabck) | git tag |
| getTagsSync() | git tag |
| createTag(name, callback) | git tag [name] |
| createTagSync(name) | git tag [name] |
| addRemote(remote, url, callback) | git remote add [remote] [url] |
| addRemoteSync(remote, url) | git remote add [remote] [url] |
| setRemoteUrl(remote, url, callback) | git remote set-url [remote] [url] |
| setRemoteUrlSync(remote, url) | git remote set-url [remote] [url] |
| removeRemote(remote, callback) | git remote rm [remote] |
| removeRemoteSync(remote) | git remote rm [remote] |
| getRemotes(callback) | git remote -v |
| getRemotesSync() | git remote -v |
| push(remote, branch, flagArray, credObject, callback) | git push [remote] [branch] [flags] |
| pull(remote, branch, flagArray, credObject, callback) | git pull [remote] [branch] [flags] |
| reset(hash, callback) | git reset --hard [hash] |
| resetSync(hash) | git reset --hard [hash] |
| describe(callback) | git describe --always |
| describeSync() | git describe --always |
| cherryPick(commit, callback) | git cherry-pick commit |
| cherryPickSync(commit) | git cherry-pick commit |
| show(commit, filePath, callback) | git show [commit]:[filepath] |
| showSync(commit, filePath) | git show [commit]:[filepath] |
| fetch(flagsArray, credObject, callback) | git fetch [flags] |
| remote(remote, flagsArray, callback) | git remote [flags] [remote] |
