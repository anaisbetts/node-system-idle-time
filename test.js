var system = require('./build/Release/system-idle-time');

setInterval(function () {
  console.log(system.getIdleTime());
}, 1000);
