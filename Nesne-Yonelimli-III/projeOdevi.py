import json

class Anket:
	def __init__(self, _id, baslik, aciklama, sorular):
		self.id = _id
		self.baslik = baslik
		self.aciklama = aciklama
		self.sorular = sorular

	def SozlugeCevir(self):
		return { "anketID": self.id, "baslik": self.baslik, "aciklama": self.aciklama, "sorular": self.sorular }

class Soru:
	def __init__(self, soru, cevap):
		self.soru = soru
		self.cevap = cevap

	def SozlugeCevir(self):
		return { "soru": self.soru, "cevap": self.cevap}

Anketler = []

def clear_console():
    print("\033[2J\033[H", end="")

def PaneliHazirla(baslik):
	clear_console()
	print(baslik + "\n")

def PaneliKapat():
	input("\nDevam etmek icin Enter a basin...")
	clear_console()

def DosyayiGuncelle(veri):
	try:
		dosya = open("ProjeOdevi\\anketler.json", "w", encoding="utf-8")
		json.dump(veri, dosya, indent = 4)
	except:
		return -1

def DosyayiAl():
	try:
		dosya = open("ProjeOdevi\\anketler.json", "r", encoding="utf-8")
		return json.load(dosya)
	except:
		return -1

def AnketOlustur():
	dosya = DosyayiAl()
	if dosya != -1:
		anketID = dosya["sonID"] + 1
		baslik = input("Anketin basligini giriniz (geri donmek icin 'q' ya da Enter): ")
		if baslik.lower() != "q" and baslik != "":
			aciklama = input("Anketin aciklamasini giriniz (geri donmek icin 'q' ya da Enter): ")
			if aciklama.lower() != "q" and aciklama != "":
				sayi = 1
				sorular = []
				while True:
					soru = input("Soru-{} (cikmak icin q) (soru iptali icin Enter a bas): ".format(sayi))
					if soru.lower() != "q":
						if soru != "":
							cevap = input("Cevap-{} (cikmak icin q) (soru iptali icin Enter a bas): ".format(sayi))
							if cevap.lower() != "q":
								if cevap != "":
									_soru = Soru(soru, cevap)
									sorular.append(_soru.SozlugeCevir())
									sayi = sayi + 1
								else:
									continue
							else:
								break
						else:
							continue
					else:
						break
				if len(sorular) > 0:
					anket = Anket(anketID, baslik, aciklama, sorular)
					dosya["anketler"].append(anket.SozlugeCevir())
					dosya["sonID"] = anketID
					if DosyayiGuncelle(dosya) == -1:
						print("Dosya guncellenirken hata olustu!")
				else:
					print("Soru eklemediginizden dolayi anket olusturulamadi!")
	else:
		print("Dosya alinirken hata olustu!")

def AnketleriGetir():
	dosya = DosyayiAl()
	if dosya != -1:
		Anketler.clear()
		for anket in dosya["anketler"]:
			Anketler.append(Anket(anket["anketID"], anket["baslik"], anket["aciklama"], anket["sorular"]))
	else:
		print("Dosya alinirken hata olustu!")

def AnketleriGoruntule():
	AnketleriGetir()
	if len(Anketler) > 0:
		for anket in Anketler:
			print("Anket ID: {}".format(anket.id))
			print("\t",end="")
			print("Baslik: {}".format(anket.baslik))
			print("\t",end="")
			print("Aciklama: {}".format(anket.aciklama))
			print("\t",end="")
			print("Sorular:")
			soruID = 1
			for soru in anket.sorular:
				print("\t",end="")
				print("\t",end="")
				print("Soru-{}: {}".format(soruID, soru["soru"]))
				print("\t",end="")
				print("\t",end="")
				print("Cevap-{}: {}".format(soruID, soru["cevap"]))
				soruID += 1
	else:
		print("Hicbir anket bulunamadi!")
	
def AnketSil():
	try:
		anketID = int(input("Silinecek anketin id sini giriniz: "))
		AnketleriGetir()
		varMi = False
		sonID = 1
		dosya = DosyayiAl()
		dosya["anketler"].clear()
		for anket in Anketler:
			if anket.id != anketID:
				sonID = anket.id
				dosya["anketler"].append(anket.SozlugeCevir())
			else:
				varMi = True
		if not varMi:
			print("Bu id ye ait anket bulunamadi!")
		else:
			DosyayiGuncelle(dosya)
			print("Anket silindi!")
	except:
		print("Hatali islem yaptiniz. Sadece sayi giriniz!")

def AnketCoz():
	try:
		anketID = int(input("Cozulecek anketin id sini giriniz: "))
		AnketleriGetir()
		anket = None
		varMi = False
		if len(Anketler) > 0:
			for _anket in Anketler:
				if _anket.id == anketID:
					anket = _anket
					varMi = True
					break
			if not varMi:
				print("Bu id ye ait anket bulunamadi!")
			else:
				dogru = 0
				yanlis = 0
				clear_console()
				print("Anket ID: {}".format(anket.id))
				print("{}\n{}".format(anket.baslik, anket.aciklama))
				for soru in anket.sorular:
					cevap = input("{}: ".format(soru["soru"]))
					if cevap == soru["cevap"]:
						dogru += 1
					else:
						yanlis += 1
				print("\nAnket sonucunuz:\nToplam soru: {}, {} dogru, {} yanlis".format(len(anket.sorular), dogru, yanlis))
		else:
			print("Hic anket bulunamadi!")
	except:
		print("Hatali islem yaptiniz. Sadece sayi giriniz!")

while True:
	print("1 -> Anket Olustur\n2 -> Anket Sil\n3 -> Anketleri Getir\n4 -> Anketi Coz\n5 -> Uygulamadan Cik")
	try:
		secim = int(input("Lutfen, sayi ile islemi giriniz: "))
		if secim == 1:
			PaneliHazirla("Anket Olusturma Paneli")
			AnketOlustur()
			PaneliKapat()
		elif secim == 2:
			PaneliHazirla("Anket Silme Paneli")
			AnketSil()
			PaneliKapat()
		elif secim == 3:
			PaneliHazirla("Anketler")
			AnketleriGoruntule()
			PaneliKapat()
		elif secim == 4:
			PaneliHazirla("Anket Cozme Paneli")
			AnketCoz()
			PaneliKapat()
		elif secim == 5:
			break
		else:
			print("Hatali secim yaptiniz!")
			PaneliKapat()
	except:
		print("Hata! Lutfen bir sayi giriniz.")
		PaneliKapat()

print("Uygulamadan cikildi!")