#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

PICSCOIND=${BITCOIND:-$BINDIR/picscoind}
PICSCOINCLI=${BITCOINCLI:-$BINDIR/picscoin-cli}
PICSCOINTX=${BITCOINTX:-$BINDIR/picscoin-tx}
PICSCOINQT=${BITCOINQT:-$BINDIR/qt/picscoin-qt}

[ ! -x $PICSCOIND ] && echo "$PICSCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
PICVER=($($PICSCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for bitcoind if --version-string is not set,
# but has different outcomes for bitcoin-qt and bitcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$PICSCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $PICSCOIND $PICSCOINCLI $PICSCOINTX $PICSCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${PICVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${PICVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
