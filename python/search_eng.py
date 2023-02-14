# Using sys arguments and rich for opening search engine in browser

# Imports
import sys
from rich.console import Console
from rich.panel import Panel
from rich.prompt import Prompt
from rich.theme import Theme
from rich.prompt import Confirm
from random import choice
import webbrowser

# Globals
engines = {
    "google": "https://www.google.com/search?q=",
    "ddg": "https://duckduckgo.com/?q=",
    "bing": "https://www.bing.com/search?q=", 
    "startpage": "https://www.startpage.com/do/metasearch.pl?query=",
    "youtube": "https://www.youtube.com/results?search_query=",
    "yt": "https://www.youtube.com/results?search_query=",
    "github": "https://github.com/search?q=",
    "gh": "https://github.com/search?q="
}
console = Console()

# Using rich to print text with a color
# text: text to print
# code: color code
# Returns None
def c_print(text, code):
    # Define themes and theme colors
    theme = Theme({
        "info": "bold cyan",
        "warning": "magenta",
        "danger": "bold red",
        "success": "bold green",
        "normal": ""
    })
    console = Console(theme=theme)
    console.print(text, style=code)

# Open search engine in browser
# engine: search engine to use
# query: query to search for
# Returns Search string to print
def open_engine(engine, query):
    if engine in engines:
        webbrowser.open(engines[engine] + query)
        return f"Searching {query} in {engine}"
    else:
        c_print("Invalid engine", "danger")

# Get args from command line or prompt user for input
# Uses rich.prompt to get input if no args are provided
# Returns a tuple of (search_engine, query)
def get_args():
    if len(sys.argv) > 1:
        return (sys.argv[1], ' '.join(sys.argv[2:]))
    else:
        c_print(
            "You didn't provide any arguments, so I'll ask you for them.", code="info")
        engine = Prompt.ask('Enter an engine: ', choices=['google', 'bing', 'ddg', 'startpage', 'github', 'yt'])
        args = Prompt.ask('Enter a query: ', default='done')
        return (engine, args)

# Main function
def main():
    # Get args
    engine, query = get_args()
    console.print(f"{open_engine(engine, query)}\n", style="bold green")

# Run main function
if __name__ == '__main__':
    main()