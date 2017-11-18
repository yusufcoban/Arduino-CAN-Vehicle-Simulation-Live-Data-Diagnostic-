# Git Controller

Git-controller is a Node.js wrapper for the Git CLI, it is extened version of [gitty](https://github.com/gordonwritescode/gitty). It's syntax resembles the Git command line
syntax, executes common commands, and parses the output into operable objects.

## Installation

### Prerequisites

* Node.js 0.12.x (http://nodejs.org)
* Git 1.7.x.x (http://git-scm.com)

```
$ npm install git-controller
```

### Testing

Run the the unit and integration tests with:

```
$ npm test
```

## Usage

```js
var git    = require('git-controller');
var myRepo = git('/path/to/repo');
```

Now you can call this instance of `Repository`'s methods. For example, to
execute `git log` for `myRepo`, you would do:

```javascript
myRepo.log(function(err, log) {
	if (err) return console.log('Error:', err);
	// ...
});
```

### Where are the Docs?

Pretty much everything you'll need is in
`lib/repository.js` and it's very readable. However you can checkout [List of functions available](https://github.com/marketlytics/git-controller/blob/master/docs/FUNCTIONS.md). 
Running the test suite will be of use as well since all public methods are tested and will print to the console.


## Authenticated Repositories

Gitty no longer supports username/password authentication over SSH. You should
be using SSH keys for that.

```javascript
myRepo.push('origin', 'master', function(err, succ) {
	if (err) return console.log(err);
	// ...
});
```

Licensed under LGPLv3 license
