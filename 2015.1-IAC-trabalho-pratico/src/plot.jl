using PyPlot

memoria = []
cpu = []
i = 1

plotFile = open("plot.txt")
lines = readlines(plotFile)

for item in lines
    column = split(item, " ")
    push!(memoria, parse(Int, column[3]))
    push!(cpu, parse(Float64, column[2]))
    i = i+1
end
close(plotFile)

subplot(211)
plot(memoria, "b-")
ylabel("Consumo Memória (KB)", color="b")
grid()
subplot(212)
plot(cpu, "g-")
ylabel("Consumo CPU (%)", color="g")
xlabel("Tempo (s)")
grid()
show()
