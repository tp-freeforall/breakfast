#!/usr/bin/env python

def checkSkew(tuples):
    startLocal = min([local for (local, remote) in tuples])
    startRemote = min([remote for (local, remote) in tuples])
    zb = [ (local - startLocal, remote - startRemote) 
      for (local, remote) in tuples]
    print "before sort:", zb
    zb = sorted(zb)
    print "after sort:", zb
    deltas = [ (localR - localL, remoteR - remoteL) 
      for ((localL, remoteL), (localR, remoteR))
      in zip(zb, zb[1:])]
    skews = [ float(dr)/float(dl) for (dl, dr) in deltas]
    avgSkew = sum(skews)/len(skews)
    return (avgSkew, skews)
