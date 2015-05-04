var system = require('./addon');

setInterval(function () {
  console.log(system.getIdleTime());
}, 1000);
