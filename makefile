# ---------------------------------------------------------------------------------
# Makefile
# $Id: makefile,v 1.2 2012/03/12 20:01:15 matsch Exp $

SOURCES = *.tex *.bib figures/*

# Default: Compile texfiles
Thesis.pdf: $(SOURCES)

	pdflatex Thesis.tex
	bibtex Thesis
	pdflatex Thesis.tex

	@while ( grep "Rerun to get cross-references" Thesis.log > /dev/null ); do \
		echo '\n Re-running LaTeX to get cross-references \n'; \
		pdflatex Thesis.tex; \
	done

	@if ( grep "LaTeX Warning: Float too large" Thesis.log > /dev/null ); then \
		echo '\nLarge floats'; \
		grep "LaTeX Warning: Float too large" Thesis.log; \
	fi

	@if ( grep "LaTeX Warning: Reference" Thesis.log > /dev/null ); then \
		echo '\nUndefined references'; \
		grep "LaTeX Warning: Reference" Thesis.log; \
	fi

	@if ( grep "LaTeX Warning: Citation" Thesis.log > /dev/null ); then \
		echo '\nUndefined citations'; \
		grep "LaTeX Warning: Citation" Thesis.log; \
	fi

#	rm ./*.toc ./*.log ./*.out


# Clean up
clean:
	rm ./*.aux ./*.toc ./*.log ./*.out ./*.blg ./*.bbl ./*~
