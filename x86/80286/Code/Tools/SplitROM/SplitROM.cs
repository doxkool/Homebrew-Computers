namespace SplitROM
{
	internal class SplitROM
	{
		static void Main(string[] args)
		{
			FileStream fs = File.OpenRead(args[0]);
			Byte tmp;
			string filePath = Environment.CurrentDirectory;
			FileStream fsMSB = File.Create(filePath + "\\" + Path.GetFileNameWithoutExtension(args[0]) + "_MSB" + Path.GetExtension(args[0]));
			FileStream fsLSB = File.Create(filePath + "\\" + Path.GetFileNameWithoutExtension(args[0]) + "_LSB" + Path.GetExtension(args[0]));
			while (fs.Position < fs.Length)
			{
				tmp = (Byte)fs.ReadByte();
				fsLSB.WriteByte(tmp);
				//fsLSB.WriteByte(tmp);
				tmp = (Byte)fs.ReadByte();
				fsMSB.WriteByte(tmp);
				//fsMSB.WriteByte(tmp);
			}
			fsMSB.Close();
			fsLSB.Close();
			fs.Close();
			Console.WriteLine(" .." + fsMSB.Name + "\n.." + fsLSB.Name + "\nFile split successful.");
		}
	}
}