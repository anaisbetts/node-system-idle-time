# Node System Idle Time

A native node addon for obtaining system idle time in seconds.

## Pre-requisites

### Linux

For Linux, you need `libxss-dev` and `libxext-dev`.

In Ubuntu 16.04, you could install them with:

```bash
sudo apt-get install libxss-dev libxext-dev
```

## Install

To install it in your project run:

```bash
npm install --save @paulcbetts/system-idle-time
```

Or if you are using [`yarn`](https://yarnpkg.com/en/), then run:

```bash
yarn add @paulcbetts/system-idle-time
```

## Usage

* In your Node JS application import it as:

```js
var systemIdleTime = require('@paulcbetts/system-idle-time');
```

* Then you can use it calling:

```js
systemIdleTime.getIdleTime();
```

* The method `getIdleTime` will return the system idle time in milliseconds.

* For example, to print to the console the idle time every second you could do this:

```js
setInterval(function () {
  console.log('Idle time: ' + systemIdleTime.getIdleTime());
}, 1000);
```

## Usage in Electron

If you are building an Electron application you need to re-build the addon using Electron's version of Node.js.

If you are using [`electron-builder`](https://github.com/electron-userland/electron-builder) to build your app, it comes with `install-app-deps`. You can re-build the module with:

```bash
./node_modules/.bin/install-app-deps
```

If you are not using `electron-builder` you can install [`electron-rebuild`](https://github.com/electron/electron-rebuild):

```bash
npm install --save-dev electron-rebuild
```

And then re-build the addon with:

```bash
./node_modules/.bin/electron-rebuild
```

## References

OS implementations derived from the following resources:

* http://www.danandcheryl.com/2010/06/how-to-check-the-system-idle-time-using-cocoa
* https://github.com/jojobyte/idlerun
* https://github.com/rosedu/Pidgin/blob/master/pidgin/gtkidle.c
