// * 1108. Defanging an IP Address

function defangIPaddr(address: string): string {
  return address.replaceAll('.', '[.]')
}
