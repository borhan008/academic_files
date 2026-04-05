from langchain_community.document_loaders import PyPDFLoader
from langchain_text_splitters  import CharacterTextSplitter
from langchain_community.vectorstores import Chroma
from langchain_community.embeddings import OllamaEmbeddings

from langchain_community.llms import Ollama

loader = PyPDFLoader("1.pdf")
docs = loader.load()
splitter = CharacterTextSplitter(chunk_size=1000, chunk_overlap=100)
chunks = splitter.split_documents(docs)


embeddings = OllamaEmbeddings(model="nomic-embed-text")

db = Chroma.from_documents(chunks, embeddings)

llm = Ollama(model="gemma3:1b")

while True:
    q = input("\nAsk: ")
    docs = db.similarity_search(q)
    context = docs[0].page_content
    answer = llm.invoke(f"Answer from thsi context : {context} \n Question: {q}")
    print(answer)
