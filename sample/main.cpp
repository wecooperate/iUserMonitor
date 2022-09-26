#include <locale>
#include <iUserMonitorSDK.h>
#include <iUserMonitorProtocol.h>

class UserMontorCallback : public IUserMonitorCallback
{
public:
	void OnCallback(IUserMonitorMessage* msg)
	{
		printf("%S ==> %S\n", msg->GetTypeName(), msg->GetFormatedString(emMSGFieldCurrentProcessPath));
		printf("\t%30S : %-30d\n", _T("ProcessType"), msg->GetHeader()->CurrentProcessType);

		for (ULONG i = emMSGFieldPath; i < msg->GetFieldCount(); i++) {
			printf("\t%30S : %-30S\n", msg->GetFieldName(i), msg->GetFormatedString(i));
		}
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "chs");

	UserMonitorManager mgr;
	UserMontorCallback callback;

	HRESULT hr = mgr.Start(&callback);

	if (hr != S_OK) {
		printf("start error = %08X", hr);
		return -1;
	}

	printf("�����ɹ�\n");
	printf("iUserMonitor�ڲ���������̳���ע�뵽��ҪHook�Ľ��̣�������ְ�ȫ���������ʾ������С�\n");
	printf("�����Ҫ���õ�ע�뷽ʽ�������ʹ��iMonitor���ں˼�ע�뷽ʽ��\n");
	printf("Ϊ���ȶ����˳��󲻻�ж���Ѿ�ע���ģ�飬�����Ҫɾ��������������ע����������ϵͳ��\n");
	printf("\n");

	WaitForSingleObject(GetCurrentThread(), INFINITE);

	return 0;
}
