n = n = 11461532818525251775869994369956628325437478510485272730419843320517940601808597552925629451795611990372651568770181872282590309894187815091191649914833274805419432525386234876477307472337026966745408507004000948112191973777090407558162018558945596691322909404307420094584606103206490426551745910268138393804043641876816598599064856358266650339178617149833032309379858059729179857419751093138295863034844253827963

k = 0
while 1:
    print k
    m2 = n + k^2
    m = isqrt(m2)
    if m^2 == n:
        print k
        break
    k = k+1
