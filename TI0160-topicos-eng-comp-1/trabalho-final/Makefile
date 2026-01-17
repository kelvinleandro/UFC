.PHONY: cli gui setup clean

setup:
	python3 -m venv .venv
	.venv/bin/pip install --upgrade pip
	.venv/bin/pip install opencv-python numpy matplotlib pillow pybind11

cli:
	rm -f histogram_cuda*.so histograma_output.png
	.venv/bin/python build.py
	.venv/bin/python main.py test_hist.png

gui:
	rm -f histogram_cuda*.so histograma_output.png
	.venv/bin/python build.py
	.venv/bin/python gui.py

clean:
	rm -rf .venv
	rm -f histogram_cuda*.so histograma_output.png
	rm -rf __pycache__
	rm -rf build/

