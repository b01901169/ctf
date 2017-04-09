
m time import clock
import math
from modules.ec import *
from modules.cryptohelp import *
from modules.dlog import *

def runDlogTest():
        alpha=random_with_bytes(1)

        #primes=[millerrabin_pseudoprime_with_bytes(i, 20) for i in range(1, 10)]
        primes = [16857450949524777441941817393974784044780411511252189319]
        #ecs=[EC(0,2,5,primes[i]) for i in range(0, 9)]
        ecs = [EC(0,16857450949524777441941817393974784044780411507861094535,77986137112576,primes[0])]
        #pts=[ecs[i].pickPoint() for i in range(0, 9)]
        pts = [(5732560139258194764535999929325388041568732716579308775, 14532336890195013837874850588152996214121327870156054248)]
        #mults=[alpha*pts[i] for i in range(0, 9)]
        mults = [(2609506039090139098835068603396546214836589143940493046, 8637771092812212464887027788957801177574860926032421582)]

        for i in range(0, 1):
                print("p = "+str(primes[i]))
                print("curve = "+str(ecs[i]))
                hw=primes[i]+1+2*math.ceil(math.sqrt(primes[i]))
                print("Running autoshanks({}, {}, {})...".format(str(pts[i]), str(mults[i]), str(hw)))

                start=clock()
                result=autoshanks(pts[i], mults[i], hw)
                end=clock()

                print("autoshanks returned {}; running time: {}".format(result, end-start))
                print("")


if __name__ == "__main__":
        runDlogTest()

