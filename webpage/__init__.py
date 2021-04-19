from flask import Flask, render_template

app = Flask(__name__)

# Render home page from external html file.
@app.route("/")
@app.route("/home")
def home():
    return render_template("index.html")

# Add another page.
@app.route("/fern")
def fraktal():
    # We can pass variables this way.
    return render_template("fern.html", content="Fern")

# Add another page.
@app.route("/other")
def other():
    return render_template("other.html")

# Run the server.
if __name__ == "__main__":
	# add debug and doesn't need to rerun after every change
    app.run(debug=True)