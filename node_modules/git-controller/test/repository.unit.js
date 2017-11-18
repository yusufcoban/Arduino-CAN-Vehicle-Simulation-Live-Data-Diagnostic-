var fs         = require('fs');
var should     = require('should');
var rimraf     = require('rimraf');
var HOME       = process.env.HOME;
var Repository = require('../lib/repository');

describe('Repository', function() {

  var repo = null;

  before(function(ready) {
    if (fs.existsSync(HOME + '/.gitty')) {
      rimraf.sync(HOME + '/.gitty');
    }

    fs.mkdirSync(HOME + '/.gitty');
    fs.mkdirSync(HOME + '/.gitty/test');

    ready();
  });

  after(function() {
    rimraf.sync(HOME + '/.gitty/test');
  });

  describe('@constructor', function() {

    it('should create an instance', function(done) {
      repo = new Repository(HOME + '/.gitty/test');
      repo.should.be.instanceOf(Repository);
      repo.on('ready', done);
    });

    it('should mark itself as ready', function(done) {
      repo._ready.should.equal(true);
      done();
    });

    it('should not be a git repo', function(done) {
      repo.initialized.should.equal(false);
      done();
    });

    it('should reference an absolute path', function(done) {
      repo.path.should.equal(HOME + '/.gitty/test');
      done();
    });

    it('should have a name equal to the dirname', function(done) {
      repo.name.should.equal('test');
      done();
    });

  });

});
