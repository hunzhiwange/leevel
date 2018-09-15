# Leevel Framework Alias

modify this file ../.git/config add alias and remote,then using git tests manager your subtree repository.

```
git testspull
```

The code below need to be add.

```
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
    logallrefupdates = true
    ignorecase = true
    precomposeunicode = true
[remote "origin"]
    url = git@github.com:hunzhiwange/leevel.git
    fetch = +refs/heads/*:refs/remotes/origin/*
[branch "master"]
    remote = origin
    merge = refs/heads/master

[remote "origin"]
        url = git@gitee.com:dyhb/leevel.git
        fetch = +refs/heads/*:refs/remotes/origin/*

[remote "tests"]
    url = git@github.com:leevels/tests.git
    fetch = +refs/heads/*:refs/remotes/tests/*

[alias]      
    tests = !git subtree pull --prefix=tests tests master \
        && :
```
