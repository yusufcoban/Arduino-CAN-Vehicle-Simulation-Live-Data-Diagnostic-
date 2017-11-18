var HOME    = process.env.HOME;
var should  = require('should');
var Command = require('../lib/command');

describe('Command', function() {

  var command = null;

  describe('@constructor', function() {

    it('should create an instance', function(done) {
      command = new Command(HOME, '', ['--help']);
      command.should.be.instanceOf(Command);
      done();
    });

    it('should save the working path', function(done) {
      command.repo.should.equal(HOME);
      done();
    });

    it('should assemble the command string', function(done) {
      command.command.should.equal('git  --help ');
      done();
    });

  });

  describe('.exec()', function() {

    it('should execute the command asynchronously', function(done) {
      command.exec(function(err, stdout, stderr) {
        should.exist(stdout);
        done();
      });
    });

  });

  describe('.execSync()', function() {

    it('should execute the command synchronously', function(done) {
      should.exist(command.execSync());
      done();
    });

  });

});
