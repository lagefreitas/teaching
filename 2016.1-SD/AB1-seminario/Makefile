filename=review-template
bibtex=references.bib

all :  pdflatex clean-but-pdf

pdflatex :
	pdflatex $(filename).tex
	bibtex $(filename)
	pdflatex $(filename).tex
	pdflatex $(filename).tex

pdf : latex
	dvipdf main.dvi

latex :
	latex main.tex
	bibtex main
	latex main.tex
	latex main.tex

clean-but-pdf :
	rm -f ${filename}.{ps,log,aux,out,dvi,bbl,blg,lof,gls,ilg,ist,glo,toc,synctex.gz} *~ *.log
