## Quick Links ##

The naclports sources maintained in git:

https://chromium.googlesource.com/external/naclports.git

## Checkout Process ##

### 1. Install Prerequisites ###

You need to install [depot\_tools](http://dev.chromium.org/developers/how-tos/install-depot-tools) in order to use gclient.

### 2. Create a Client View Directory ###

```
mkdir naclports
cd naclports
```

### 3. Create a .gclient Configuration ###

```
gclient config --name=src  https://chromium.googlesource.com/external/naclports.git
```

### 4. Sync to the repos ###
```
gclient sync
```

## Checking out a branch (e.g. pepper\_42) ##

```
git checkout -b pepper_42 origin/pepper_42
gclient sync
```