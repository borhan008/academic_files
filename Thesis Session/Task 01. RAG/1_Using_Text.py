from langchain_community.llms import Ollama

llm = Ollama(model="gemma3:1b")

context = """
Python is a popular programming language.
It is used for AI, web development, and automation.
Python is beginner-friendly.

Artificial Intelligence (AI) allows machines to think and learn.
AI is used in chatbots, self-driving cars, and recommendations.
"""
print("Ask question (-1 to end)")

while True:
    question = input("\nAsk : ")
    if question == "-1":
        break
    prompt = f"""
    Answer the question using only this information
    {context}
    Question : {question}
    """

    response = llm.invoke(prompt)
    print("\nAnswer:", response)
    