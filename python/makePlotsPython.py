import ROOT as r 

#Example with draw statements:
inputFile = r.TFile("inputs/MilliQan_Run507_default_v28.root")
inputTree = inputFile.Get("t")
heightHistoDraw = r.TH1D("heightChan16","chan16;height",100,0,100)
inputTree.Draw("height>>"+heightHistoDraw.GetName(),"chan==16&&ipulse==0")
oC = r.TCanvas()
heightHistoDraw.Draw("")
oC.SaveAs("heightHistoFromDraw.pdf")

#Example with RDataframe:
df = r.RDataFrame("t",inputFile)
heightHistoRDF = df.Define("heightChan16","height[chan==16&&ipulse==0]").Filter("Sum(chan==16&&ipulse==0)>0").Histo1D(("heightChan16_RDF","chan16;height",100,0,100),"heightChan16")
oC = r.TCanvas()
heightHistoRDF.Draw()
oC.SaveAs("heightHistoFromRDF.pdf")

