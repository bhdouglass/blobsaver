# BlobSaver

This a hack for Ubuntu Touch Webapps to be able to support `blob:` urls.
BlobSaver overwrites the `URL.createObjectURL` method and passes the blob's data
to the QML, which in turn passes that data to a C++ function that saves it to
the app's cache directory.

You can see BlobSaver inaction in the [Photopea Webapp](https://github.com/bhdouglass/photopea-webapp).

## Usage

~~~
import BlobSaver 1.0

...

WebContext {
    ...

    userScripts: [
        BlobSaverUserScript {}
    ]
}

WebView {
    ...

    messageHandlers: [
        BlobSaverScriptMessageHandler {
            cb: function(path) {
                /*
                path is the full path to the file, you can use it to open in
                another app for example.

                When you are done with the file you can optionally use
                BlobSaver.remove(path) to remove the file.
                */
            }
        }
    ]
}
~~~

## License

Copyright (C) 2018 [Brian Douglass](http://bhdouglass.com/)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License version 3, as published
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranties of MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
