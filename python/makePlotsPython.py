import ROOT as r 

inputFile = r.TFile("inputs/MilliQan_Run507_default_v28.root")
inputTree = inputFile.Get("t")
oC = r.TCanvas()
#Example with looper (slow):
heightHistoLooper = r.TH1D("heightChan16Looper","chan16;height",100,0,100)
for event in inputTree:
    for iPulse in range(len(event.height)):
        if (event.chan[iPulse] == 16 and event.ipulse[iPulse] == 0):
            heightHistoLooper.Fill(event.height[iPulse])
heightHistoLooper.Draw("")
oC.SaveAs("heightHistoFromLooper.pdf")

#Example with draw statements:
heightHistoDraw = r.TH1D("heightChan16Draw","chan16;height",100,0,100)
inputTree.Draw("height>>"+heightHistoDraw.GetName(),"chan==16&&ipulse==0")
heightHistoDraw.Draw("")
oC.SaveAs("heightHistoFromDraw.pdf")

#Example with RDataframe:
df = r.RDataFrame("t",inputFile)
heightHistoRDF = df.Define("heightChan16","height[chan==16&&ipulse==0]").Filter("Sum(chan==16&&ipulse==0)>0").Histo1D(("heightChan16_RDF","chan16;height",100,0,100),"heightChan16")
oC = r.TCanvas()
heightHistoRDF.Draw()
oC.SaveAs("heightHistoFromRDF.pdf")

