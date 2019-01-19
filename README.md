
Picscoin Core integration/staging tree
=====================================
https://picscoins.org

[![Build Status](https://travis-ci.org/minblock/picscoin.svg?branch=master)](https://travis-ci.org/minblock/picscoin)

Copyright (c) 2018-2019 Picscoin Developer

What is Picscoin?
----------------

Picscoin is a lite version of Bitcoin using scrypt as a proof-of-work algorithm.
 - 2.5 minute block targets
 - subsidy halves in 840k blocks (~4 years)
 - ~42 million total coins

The rest is the same as Bitcoin.
 - 50 coins per block
 - 2016 blocks to retarget difficulty

An experimental digital currency that enables storage and retreivable of pictures/photos. Each block will represent an image store for retreivable with RPC and API. Private Encrypted messaging / instant payments as well as satellite internet for PIC transfers along with a Picture as receipt. The API will be deployed on the Picscoin blockchain for implementation to Bitcoin and other top Blockchains  (https://explorer.picscoins.org) is the experimental block explorer based on the Iquidos Block Explorer that will integrate picture link (hybrid ftp/samba server protocol) into the block hash. Picscoin Core is the name of the program that enables the use of this digital currency. Picscoin is completely anonymous. Having Segwith deployed allows PIC's to be sent anonymously. Two payments can go to the same address but once payment is received, the wallet address changes, making tracing transactions impossible. Your picture will be hashed into the blockchain for future retreival and an ANSI (text-based l33t) picture confirmation as well as a universally checkable timestamp. This allows you to patent and share your  pictellectual property through any means. 

For more information visit [https://bitwall.ca](https://bitwall.ca).

License
-------

Picscoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is where the latest Picscoins developmental builds are being deployed to tags and releases. All Releases are to be considered Developmental as well as latest stable builds. Stable builds begin with a v.  [Tags](https://github.com/minblock/picscoin/tags) are created generated sequentially to indicate new compilation ready releases of Picscoin Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://groups.google.com/forum/#!forum/picscoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer IRC can be found on Freenode at #picscoin-dev.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.
### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

We only accept translation fixes that are submitted through [Bitcoin Core's Transifex page](https://www.transifex.com/projects/p/bitcoin/).
Translations are converted to Picscoin periodically.

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Copyright (c) 2011-2019 Litecoin Core Developers. 
Portions Copyright (c) 2018-2019 stevecat.
