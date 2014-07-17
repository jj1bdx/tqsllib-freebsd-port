# FreeBSD port for tqsllib

* Note: TrustedQSL has been removed; it's available in Port `comms/trustedqsl`.

* See <http://sourceforge.net/projects/trustedqsl/> and <http://www.arrl.org/lotw/> for the details.

## On V2.4 converter.cpp

* Duplication is allowed by default (no BDB enabled)

## About `config.xml`

* Current version of `config.xml`: Version 2.8
* See <https://lotw.arrl.org/lotwuser/config.tq6> for the details

* NOTE WELL: how to convert config.tq6 into config.xml
    1. `gunzip -c config.tq6 > config.xml`
    2. Remove `<tqsldata>` tags (currently non-existent)


